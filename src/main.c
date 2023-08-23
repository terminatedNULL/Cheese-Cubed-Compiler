#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "definitions.h"
#define extern_
    #include "data.h"
#undef extern_
#include "declarations.h"

static void init(void) {
    line = 1;
    holdChar = '\n';
}

int main(int argc, char *argv[]) {
    const char* debugFilePath = "baseTest.txt";
    inFile = fopen(debugFilePath, "r");

    if (!inFile) {
        fprintf(stderr, "Failed to open file %s\n", argv[1]);
        exit(-1);
    }

    init();

    ASTnode* node;

    scan(&currToken);
    node = binaryExpr();
    printf("%d\n", interpretAST(node));

    fclose(inFile);
    exit(0);
}