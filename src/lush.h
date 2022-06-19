#ifndef LUSH_H
#define LUSH_H

typedef enum {
	L_NIL,
	L_CMD,
	L_ARG,
	L_IO_NUMBER,/*[n]>*/
	L_LANG,		/* <  */
	L_DLANG,	/* << */
	L_TlANG,	/* <<<*/
	L_RANG,		/* >  */
	L_DRANG,	/* >> */
	L_PIPE,		/* |  */
	L_SEMICO,	/* ;  */
	L_AMP,		/* &  */
	L_DAMP,		/* && */
} lush_token;

#endif
