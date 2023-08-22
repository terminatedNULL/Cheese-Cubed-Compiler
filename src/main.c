#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "scan.c"

#include "data.h"
#include "definitions.h"

int line;
int holdChar;
FILE* inFile;

char* tokenStr[] = { "+", "-", "*", "/", "intlit" };

static void scanFile();

int CALLBACK WinMain(
    HINSTANCE   hInstance,
    HINSTANCE   hPrevInstance,
    LPSTR       lpCmdLine,
    int         nCmdShow
)
{
    const char* debugFilePath = "baseTest.txt";

    inFile = fopen(debugFilePath, "r");

    scanFile();

	return 0;
}

static void scanFile() {
    token T;

    while (scan(&T)) {
        printf("Token %s", tokenStr[T.token]);
        if (T.token == T_INT_LITERAL) {
            printf(", value %d", T.intValue);
        }
        printf("\n");
    }
}