#include <stdio.h>
#include "lex.h"

int main()
{
	lush_lex(" math.random    0 9 2> 'secret file' &");
	/* lush_lex("'here is a dquote: \"' \"following\" 'two args'"); */
	/* lush_lex("\"dquote: \\\\\" \" following\" args"); */
	/*         "dquote: \\"" */
	/* lush_lex(""); */
}
