#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

// SymbolTable
// i  = iteration for SymbolTable
// pc = program counter for variables
struct variable SymbolTable[300];
int numOfVar  = 0;
int addrSize  = 0;

int insert(char* nameVar, int typeVar, int size)
{
    for(int i = 0; i < numOfVar; i++)
    {
      struct variable iter = SymbolTable[i];
        if(strcmp(iter.name, nameVar) == 0)
        {
            return 1;
        }
    }
    struct variable varIn;
    varIn.name = nameVar;
    varIn.type = typeVar;
    varIn.addr = addrSize;
    varIn.size = size;

    SymbolTable[numOfVar] = varIn;
    addrSize += size;
    numOfVar++;
    return 0;
}
void displayTable()
{
    printf("Name:\t\t\tType\t\tAddress\t\tSize\n");
    printf("---------------------------------------------------------------\n");
    char* type;

    for(int i = 0; i < numOfVar; i++)
    {
        struct variable iter = SymbolTable[i];
        if(iter.type == 1) { type = "REAL"; }
        else { type = "INTEGER"; }
        printf("%s\t\t\t", iter.name);
        printf("%s\t\t", type);
        printf("%d\t\t", iter.addr);
        printf("%d\n", iter.size);
    }
}
