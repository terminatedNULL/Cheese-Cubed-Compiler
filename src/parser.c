#include "data.h"
#include "definitions.h"

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