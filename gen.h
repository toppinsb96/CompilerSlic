#ifndef GEN_H
#define GEN_H
#include "ast.h"
#include "symbol.h"

void generateCode(ast *a);
void generateAssign(ast *a);
int generateVar(ast *a);
int generateExpr(ast *a);
void generateISP(struct variable *SymbolTable, int numOfVar);
void addCode(char* str);
void printInstructions();
#endif
