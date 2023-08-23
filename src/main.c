#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "definitions.h"
#include "data.h"
#include "declarations.h"

static void init(void) {
    line = 1;
    holdChar = '\n';
}

int main(int argc, char *argv[]) {
    const char* debugFilePath = "bseTest.txt";
    inFile = fopen(debugFilePath, "r");

    if (!inFile) {
        fprintf(stderr, "Failed to open file %s\n", argv[0]);
        exit(-1);
    }

    ASTnode* node;

    scan(&currToken);
    node = binaryExpr();
    printf("%d\n", interpretAST(node));

    fclose(inFile);
    exit(0);
}