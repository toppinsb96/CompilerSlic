#include "gen.h"
#include "y.tab.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int ISP_MEMORY_SIZE = 0;
char* instructions[10000];
int index_ins = 0;
int divisorLoc;
int dividendLoc;

ast* root;

void generateCode(ast* a)
{
    if(!root)
    {
        printf("EMPTY ALGORITHM SECTION\n");
        return;
    }
    createModMemory();
    do
    {

        generateAssign(a);
        a = a->next;
    } while(a);
}
void createModMemory()
{
    /*
    divisorLoc = index_ins;
    dividendLoc = index_ins + 1;
    index_ins += 2; // creates two slots in memory for modulos expressions*/
}
void generateAssign(ast *a)
{
    //printf("generateAssign: type is: %d, printtype: %d\n", a->type, PRINT);
    if(a->type == ASSIGNMENT)
    {
        int L = generateVar(a->left);
        int R = generateExpr(a->right);

        if(L == INTCONSTANT && R == FLOATCONSTANT)
        {
          addCode("FTI");
        }
        else if(L == FLOATCONSTANT && R == INTCONSTANT)
        {
          addCode("ITF");
        }
        addCode("STO");
    }
    else if(a->type == PRINT)
    {
        generatePrinting(a->right);
    }
    else if(a->type == READ)
    {
        int type = generateVar(a->left);

        if (type == INTCONSTANT) { addCode("INI"); }
        else                     { addCode("INF"); }
        addCode("STO");
    }
    else if(a->type == IF)
    {

    }
    else
    {
        printf("\n\nAt the end of the generateAssign function.\n\n");
    }
}
int generateVar(ast *a)
{
    char *varType = a->c;
    struct variable var = lookup(varType);
    char* codeStr = malloc(sizeof(char) * 50);
    sprintf(codeStr, "LAA %d ; %s", var.addr, var.name);
    addCode(codeStr);

    if(var.size > 1)
    {

        int type = generateExpr(a->cond);
        if(type == FLOATCONSTANT)
        {
            addCode("FTI");
        }
        //printf("adding code?");
        addCode("ADI"); // adds address + offset
    }

    if(var.type == 0) { return INTCONSTANT; }
    else { return FLOATCONSTANT; }
}
int generateExpr(ast *a)
{
    char* codeStr = malloc(sizeof(char) * 50);

    if(a->type == INTCONSTANT)
    {
        sprintf(codeStr, "LLI %d", a->d);
        addCode(codeStr);
        return INTCONSTANT;
    }
    else if(a->type == FLOATCONSTANT)
    {
        sprintf(codeStr, "LLF %f", a->f);
        addCode(codeStr);
        return FLOATCONSTANT;
    }
    else if(a->type == VARIABLE)
    {
        int type = generateVar(a);
        addCode("LOD");
        return type;
    }
    else if(a->cond)
    {
        //TODO: Handle cond for lists
        int type = generateExpr(a->cond);

        if(a->type == NOT)
        {
            if(type == FLOATCONSTANT)
            {
                sprintf(codeStr, "LLI %f", 1.0f);
                addCode(codeStr);
                addCode("GEI");
                sprintf(codeStr, "LLI %f", 1.0f);
                addCode(codeStr);
                addCode("SBI");
            }
            else if(type == INTCONSTANT)
            {
                // Recalculate Later on
                sprintf(codeStr, "LLF %f", 1.0f);
                addCode(codeStr);
                addCode("GEF");
                sprintf(codeStr, "LLF %f", 1.0f);
                addCode(codeStr);
                addCode("SBF");
            } else { printf("ERROR: NO TYPE FOR NOT\n"); }
        }
        else if(a->type == SUB)
        {
            if(type == INTCONSTANT)
            {
              addCode("NGI");

            }
            else if(type == FLOATCONSTANT)
            {
              addCode("NGF");

            } else { printf("ERROR: NO TYPE FOR SUB\n"); }
        }
    }
    else if(a->type == MOD)
    {
        //TODO: Modulos
        modulos(a);
    }
    else
    {
        //TODO: Casting
        int left = generateExpr(a->left);
        int castPos = index_ins;
        int right = generateExpr(a->right);

        int intChecker = 1;
        if(left == INTCONSTANT && right == FLOATCONSTANT)
        {
          insertCode("ITF", castPos);
          intChecker = 0;
        }
        else if(left == FLOATCONSTANT && right == INTCONSTANT)
        {
          addCode("ITF");
          intChecker = 0;
        }
        if(intChecker)
        {
            switch(a->type)
            {
                case EQ:
                  addCode("EQI"); break;
                case NEQ:
                  addCode("NEI"); break;
                case LT:
                  addCode("LTI"); break;
                case GT:
                  addCode("GTI"); break;
                case LE:
                  addCode("LEI"); break;
                case GE:
                  addCode("GEI"); break;
                case OR:
                  addCode("ADI"); break;
                case AND:
                  addCode("MLI"); break;
                case ADD:
                  addCode("ADI"); break;
                case SUB:
                  addCode("SBI"); break;
                case MUL:
                  addCode("MLI"); break;
                case DIV:
                  addCode("DVI"); break;
            }
        }
        else
        {
            switch(a->type)
            {
                case EQ:
                  addCode("EQF"); break;
                case NEQ:
                  addCode("NEF"); break;
                case LT:
                  addCode("LTF"); break;
                case GT:
                  addCode("GTF"); break;
                case LE:
                  addCode("LEF"); break;
                case GE:
                  addCode("GEF"); break;
                case OR:
                  addCode("ADF"); break;
                case AND:
                  addCode("MLF"); break;
                case ADD:
                  addCode("ADF"); break;
                case SUB:
                  addCode("SBF"); break;
                case MUL:
                  addCode("MLF"); break;
                case DIV:
                  addCode("DVF"); break;
            }
        }
        if(intChecker)
        {
            return INTCONSTANT;
        } else
        {
            return FLOATCONSTANT;
        }
    }
    return WHITESPACE;
}
void generatePrinting(ast* a)
{
    //printf("type: %d, strchar: %d\n", a->type, STRCHARCONSTANT);
    do {
      if(a->type == STRCHARCONSTANT)
      {
          addCode("NOP ; Printing");
          int len = strlen(a->c);

          for(int i = 0; i < len; i++)
          {
              char* codeStr = malloc(sizeof(char) * 50);
              char c = a->c[i];
              sprintf(codeStr, "LLI %d", (int)c);
              addCode(codeStr);
              addCode("PTC");
          }
      }
      else if(a->type == CARRIAGE)
      {
          addCode("PTL");
      }
      else if(a->type)
      {
          int type = generateExpr(a);
          if(type == INTCONSTANT)
          {
            addCode("PTI");
          }
          else if(type == FLOATCONSTANT)
          {
            addCode("PTF");
          }
      }
      a = a->next;
    } while(a);
}
int modulos(ast* a)
{

    // a = aab/b*-
    int left = generateExpr(a->left);
    int left2 = generateExpr(a->left);   // TODO: Figure out how to not have to re-evaluate
    int right = generateExpr(a->right);
    addCode("DVI");
    int right2 = generateExpr(a->right); // TODO: Figure out how to not have to re-evaluate
    addCode("MLI");
    addCode("SBI");
    return INTCONSTANT;
}
void generateISP(struct variable *SymbolTable, int numOfVar)
{
    char *ISP_IN = malloc(sizeof(char) * 50);;
    for(int i = 0; i < numOfVar; i++)
    {
        ISP_MEMORY_SIZE += SymbolTable[i].size;
    }
    sprintf(ISP_IN, "ISP %d", ISP_MEMORY_SIZE);
    instructions[index_ins] = ISP_IN;
    index_ins++;
}

void addCode(char* str)
{

    instructions[index_ins] = str;
    index_ins++;
}
void insertCode(char* str, int pos)
{
    for(int i = index_ins; i > pos; i--)
    {
        instructions[i+1] = instructions[i];
    }
    //BUG: Possible bug with the pos+1
    instructions[pos] = str;
    index_ins++;
}
void printInstructions()
{

    for(int i = 0; i < index_ins; i++)
    {
        printf("%d: ", i);
        printf("%s\n", instructions[i]);
    }
}
