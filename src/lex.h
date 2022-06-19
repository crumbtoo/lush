#ifndef LEX_H
#define LEX_H

typedef enum {
	NIL,
	CMD,
	ARG,
	LANG,		/* <  */
	DLANG,		/* << */
	TlANG,		/* <<<*/
	RANG,		/* >  */
	DRANG,		/* >> */
	PIPE,		/* |  */
} lush_token;

lush_token *lush_lex(const char *s);

#endif
