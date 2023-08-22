#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#include "scan.c"

#include "data.h"
#include "definitions.h"

int iine;
int holdChar;
FILE* inFile;

char tokenStr[5][10] = {
    "+",
    "-",
    "*",
    "/",
    "intLit"
};

int CALLBACK WinMain(
    HINSTANCE   hInstance,
    HINSTANCE   hPrevInstance,
    LPSTR       lpCmdLine,
    int         nCmdShow
)
{
    std::string debugFilePath = "testCheeseFile.txt";

    inFile = fopen(debugFilePath.c_str(), "r");

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