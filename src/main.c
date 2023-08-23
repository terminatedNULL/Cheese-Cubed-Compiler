#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "scan.c"

#include "data.h"
#include "definitions.h"

int line = 0;
int holdChar = 0;
FILE* inFile;

char* tokenStr[] = { "+", "-", "*", "/", "intlit" };

static void scanFile();


int main() {
    const char* debugFilePath = "baseTest.txt";

    inFile = fopen(debugFilePath, "r");

    if (!inFile) {
        printf("Failed to open file");

        exit(-1);
    }

    scanFile();  

    fclose(inFile);

	return 0;
}

static void scanFile() {
    struct token T;

    while (scan(&T)) {
        printf("Token %s", tokenStr[T.token]);
        if (T.token == T_INT_LITERAL) {
            printf(", value %d", T.intValue);
        }
        printf("\n");
    }
}