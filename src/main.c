#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "scan.c"
#include "tree.c"
#include "parser.c"

#include "data.h"
#include "definitions.h"

static void scanFile(void);

int line = 0;
int holdChar = 0;
FILE* inFile;
Token currToken;

int main(int argc, char *argv[]) {
    const char* debugFilePath = "baseTest.txt";

    inFile = fopen(debugFilePath, "r");

    if (!inFile) {
        fprintf(stderr, "Failed to open file %s\n", argv[0]);
        exit(-1);
    }

    scanFile();  

    fclose(inFile);

	return 0;
}

static void scanFile(void) {
    char* tokenStr[] = { "+", "-", "*", "/", "intlit" };
    Token T;

    while (scan(&T)) {
        printf("Token %s", tokenStr[T.Token]);
        if (T.Token == T_INT_LITERAL) {
            printf(", value %d", T.intValue);
        }
        printf("\n");
    }
}