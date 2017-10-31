/*
 * ========================================================================
 *
 * main.c ----- In-class example of a main program file to be used in
 *                conjunction with a yacc parser.
 *
 * Programmer --- Bryan Crawley
 *
 * ========================================================================
 */

#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include "symbol.h"
#include "ast.h"
#include "gen.h"

int main()
{
    if(yyparse())
    {

      printf("ERROR! \n");
    }
    else
    {
      generateISP(SymbolTable, numOfVar);
      //printf("I'm here\n");
      generateCode(root);
      //displayTable();
      printInstructions();
    }
    return 0;
}
