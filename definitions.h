#ifndef DEFINITIONS_H
#define DEFINITIONS_H

struct token {
	int token;
	int tokenValue;
};

enum {
	T_PLUS,
	T_MINUS,
	T_STAR,
	T_SLASH,
	T_INT_LITERAL
};

#endif