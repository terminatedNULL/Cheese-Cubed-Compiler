#include "data.h"

static int next(void) {
	int c;

	if (putback) {
		c = putback;
		putback = 0;
		return c;
	}

	c = fgetc(inFile);
	if (c == '\n') { line++; }
	return c;
}