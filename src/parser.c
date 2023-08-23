#include "definitions.h"
#include "data.h"
#include "declarations.h"

int arithmeticOp(int token) {
	switch (token) {
	case T_PLUS:
		return A_ADD;
	case T_MINUS:
		return A_SUBTRACT;
	case T_STAR:
		return A_MULTIPLY;
	case T_SLASH:
		return A_DIVIDE;
	default:
		fprintf(stderr, "Unknown token passed into function arithmeticOp() on line %d\n", line);
		exit(-1);
	}
}

static ASTnode* literalNode(void) {
	ASTnode *node;

	switch (currToken.Token) {
	case T_INT_LITERAL:
		node = createASTLeaf(A_INT_LITERAL, currToken.intValue);
		scan(&currToken);
		return node;
	default:
		fprintf(stderr, "Syntax error on line %d\n", line);
		exit(-1);
	}
}

ASTnode *binaryExpr(void) {
	ASTnode *node, *right, *left;
	int nodeType;

	left = literalNode();
	if (currToken.Token == T_EOF) { return left; }

	nodeType = arithmeticOp(currToken.Token);
	scan(&currToken);

	right = binaryExpr();

	node = createASTNode(nodeType, 0, right, left);

	return node;
}