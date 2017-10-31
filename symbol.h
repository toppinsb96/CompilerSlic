#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct variable {
    char* name;
    int type; // 0 = int, 1 = real
    int addr;
    int size;
} var;

// SymbolTable
extern struct variable SymbolTable[1000];
extern int numOfVar;
int insert(char* nameVar, int typeVar, int size);
void displayTable();
struct variable lookup(char* value);
