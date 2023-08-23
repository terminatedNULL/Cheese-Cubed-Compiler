#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum {
	T_EOF,
	T_PLUS,
	T_MINUS,
	T_STAR,
	T_SLASH,
	T_INT_LITERAL,
	T_OPEN_PAREN,
	T_CLOSE_PAREN,
};

enum {
	A_ADD,
	A_SUBTRACT,
	A_MULTIPLY,
	A_DIVIDE,
	A_INT_LITERAL,
	A_OPEN_PAREN,
	A_CLOSE_PAREN,
};

typedef struct {
	int Token;
	int intValue;
} Token;

typedef struct {
	int op;
	int intValue;
	struct ASTnode *right;
	struct ASTnode *left;
} ASTnode;

#endif