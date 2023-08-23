int scan(Token* t);

ASTnode* createASTNode(int op, int intValue, ASTnode *right, ASTnode *left);
ASTnode* createASTLeaf(int op, int intValue);
ASTnode* createASTUnary(int op, int intValue, ASTnode *left);
ASTnode* binaryExpr();

int interpretAST(ASTnode* node);