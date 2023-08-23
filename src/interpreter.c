#include "definitions.h"
#include "data.h"
#include "declarations.h"

int interpretAST(ASTnode* node) {
	int leftVal, rightVal;

	if (node->left) { leftVal = interpretAST(node->left); }
	if (node->right) { rightVal = interpretAST(node->right); }

	switch (node->op) {
	case A_ADD:
		return (leftVal + rightVal);
	case A_SUBTRACT:
		return (leftVal - rightVal);
	case A_MULTIPLY:
		return (leftVal * rightVal);
	case A_DIVIDE:
		return (leftVal / rightVal);
	case A_INT_LITERAL:
		return node->intValue;
	default:
		fprintf(stderr, "Unknown AST operator %d\n", node->op);
		exit(-1);
	}
}