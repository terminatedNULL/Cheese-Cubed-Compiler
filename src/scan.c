#include <ctype.h>

#include "data.h"
#include "definitions.h"

static int next(void) {
	int c;

	if (holdChar) {
		c = holdChar;
		holdChar = 0;
		return c;
	}

	c = fgetc(inFile);
	if (c == '\n') { line++; }
	return c;
}

static void putBack(int c) {
	holdChar = c;	
}

static int skip(void) {
	int c;

	c = next();
	while (c == ' ' || c == '\t' || c == '\n' || c == '\r' | c == '\f') {
		c = next();
	}

	return c;
}

static int charPos(char* s, int c) {
	char* p;

	p = strchr(s, c);
	return (p ? p - s : -1);
}

static int scanInt(int c) {
	int k, val = 0;

	while ((k = charPos("0123456789", c)) >= 0) {
		val = val * 10 + k;
		c = next();
	}

	putBack(c);
	return val;
}

static int scan(struct token *t) {
	int c;

	c = skip();

	switch (c) {
	case EOF:
		return 0;
	case '+':
		t->token = T_PLUS;
		break;
	case '-':
		t->token = T_MINUS;
		break;
	case '*':
		t->token = T_STAR;
		break;
	case '/':
		t->token = T_SLASH;
		break;
	default:
		if (isdigit(c)) {
			t->intValue = scanInt(c);
			t->token = T_INT_LITERAL;
			break;
		}
		printf("Unrecognized character %c on line %d\n", c, line);
		exit(-1);
	}

	return 1;
}