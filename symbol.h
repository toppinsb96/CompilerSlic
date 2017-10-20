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
// i  = iteration for SymbolTable
// pc = program counter for variables
extern struct variable SymbolTable[300];
extern int numOfVar;

int insert(char* nameVar, int typeVar, int size);
void displayTable();
