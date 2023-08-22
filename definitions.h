#ifndef DEFINITIONS_H
#define DEFINITIONS_H

typedef struct {
	int token;
	int tokenValue;
} token;

enum {
	T_PLUS,
	T_MINUS,
	T_STAR,
	T_SLASH,
	T_INT_LITERAL,
	T_WORD_LITERAL,

};

#endif