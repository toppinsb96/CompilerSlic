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

main()
{
    if(yyparse())
    {
       printf("ERROR! \n");
    }
    else
    {
        displayTable();
    }
    return 0;
}
