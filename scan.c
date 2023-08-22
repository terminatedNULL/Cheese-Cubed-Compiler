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

int scan(token *t) {
	int c;

	c = skip();

	switch (c) {
	case EOF:
		return 0;
	case '+':
		return t->token = T_PLUS;
	case '-':
		return t->token = T_MINUS;

	}
}