#ifndef DEFINITIONS_H
#define DEFINITIONS_H

struct token {
	int token;
	int intValue;
};

enum {
	T_PLUS,
	T_MINUS,
	T_STAR,
	T_SLASH,
	T_INT_LITERAL,
	T_OPEN_PAREN,
	T_CLOSE_PAREN
};

#endif