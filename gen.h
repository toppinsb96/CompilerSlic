#ifndef GEN_H
#define GEN_H
#include "ast.h"
#include "symbol.h"

void generateCode(ast *a);
void createModMemory();
void generateAssign(ast *a);
int generateVar(ast *a);
int generateExpr(ast *a);
void generatePrinting(ast* a);
int modulos(ast* a);
void generateISP(struct variable *SymbolTable, int numOfVar);
void addCode(char* str);
void insertCode(char* str, int pos);
void printInstructions();
#endif
