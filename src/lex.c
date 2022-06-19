#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "lush.h"

#define LUSH_DELIMS " \t"
#define LUSH_ALLOC_INCR 16

typedef struct
{
	uint16_t index;
	uint16_t len;
	lush_token type;
} l_tokenmap;

/* strcspn() but respects quotation & operators. */
static uint16_t q_strcspn(const char *s, const char *reject, bool *inquote, char *qtype)
{
	uint16_t i;
	bool isEscaped;
	for(i = 0; s[i] != 0; i++)
	{
		/* reset  */
		isEscaped = false;
		
		if(s[i] == '\\' && !isEscaped)
			isEscaped = true;

		/* compare s[i] with each LUSH_DELIM, if theres a match set r to 1 */
		uint8_t isDelim = 0;
		for(uint8_t k = 0; reject[k]; k++)
		{
			if(!isEscaped && s[i] == reject[k])
			{
				isDelim = 1;
				break;
			}
		}

		if(isDelim)
		{
			if(*inquote)
				continue;
			else
				return i;
		}
		else if(s[i] == '\'' || s[i] == '"') /* if double or single quote */
		{
			/* if in quote AND qtype == current char */
			if(*inquote && *qtype == s[i])
			{
				if(*qtype == '"')
				{
					if(isEscaped)
						continue;
					*inquote = false;
				}
				else if(*qtype == '\'')
				{
					*inquote = false;
				}
			}
			else
			{
				if(isEscaped)
					continue;

				*qtype = s[i];
				*inquote = true;
			}
		}
	}

	return i;
}

/* leave public for line editor access?
could be useful for syntax highlighting */

/* returns a list of struct containing the indexes of tokens (terms) */
static l_tokenmap *map_tokens(const char *s)
{
	/* used for expanding `t` as needed */
	uint16_t t_alloc = 16;
	uint16_t t_cx = 0;
	l_tokenmap *t = calloc(sizeof(l_tokenmap), t_alloc);


	/* iterate through each char */
	const char *c = s;
	bool inquote = false;
	char qtype = 0;

	do {
		/* skip leading delimiters */
		c += strspn(c, LUSH_DELIMS);

		uint16_t end = q_strcspn(c, LUSH_DELIMS, &inquote, &qtype);

		/**/
		char buf[end + 1];
		strncpy(buf, c, end);
		buf[end] = 0;
		printf("%ld-%d [%s]\n", c - s, end, buf);
		/**/

		l_tokenmap ltm = {c - s, end, 0};
		t[t_cx++] = ltm;

		c += end;
	} while(*c++);


	return t;
}

lush_token *lush_lex(const char *s)
{
	/* set after L_CMD is found to
	differentiate L_CMD and L_ARG's */
	/* bool isnextarg = false; */

	l_tokenmap *tm = map_tokens(s);
	for(int i = 0; tm[i].len != 0; i++)
	{
		char *text = strndup(s + tm[i].index, tm[i].len);
		printf("[%s]\n", text);
		printf("%d.index: %hu\n", i, tm[i].index);
		printf("%d.len:   %hu\n", i, tm[i].len);
		printf("%d.type:  %u\n\n", i, tm[i].type);
		free(text);
	}
	

	return 0;
}
