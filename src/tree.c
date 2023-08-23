#include "definitions.h"
#include "data.h"
#include "declarations.h"

ASTnode *createASTNode(int op, int intValue, ASTnode *right, ASTnode *left) {
	ASTnode *node;

	node = (ASTnode*)malloc(sizeof(ASTnode));
	if (node == NULL) {
		fprintf(stderr, "Unable to allocate memory in function createASTNode()\n");
		exit(-1);
	}

	node->op = op;
	node->intValue = intValue;
	node->right = right;
	node->left = left;

	return node;
}

ASTnode *createASTLeaf(int op, int intValue) {
	return createASTNode(op, intValue, NULL, NULL);
}

ASTnode* createASTUnary(int op, int intValue, ASTnode* left) {
	return createASTNode(op, intValue, NULL, left);
}