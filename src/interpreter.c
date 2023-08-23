#include "definitions.h"
#include "data.h"
#include "declarations.h"

static char* ASTop[] = { "+", "-", "*", "/" };

int interpretAST(ASTnode* node) {
	int leftVal, rightVal;

	if (node->left) { leftVal = interpretAST(node->left); }
	if (node->right) { rightVal = interpretAST(node->right); }

	// Debug: Print what we are about to do
	if (node	->op == A_INT_LITERAL)
		printf("int %d\n", node->intValue);
	else
		printf("%d %s %d\n", leftVal, ASTop[node->op], rightVal);

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