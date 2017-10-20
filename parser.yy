%{

/*
 * ========================================================================
 *
 * Programmer --- Brandon Toppins
 * 11 October 2017
 * Compiler Construction --- Crawley
 *
 * ========================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "symbol.h"

int yylex();
char* yytext;

extern int symbolType;
%}

%union
{
    char* str;
    int d;
}

%token  <str> VARIABLE
%token        MAIN
%token        END
%token        DATA
%token        ALGORITHM
%token        WHILE
%token        COUNTING
%token        UPWARD
%token        DOWNWARD
%token        TO
%token        IF
%token        ELSE
%token        READ
%token        PRINT
%token   <d>  INTCONSTANT
%token        FLOATCONSTANT
%token        STRCHARCONSTANT
%token        CARRIAGE
%token        ENDST
%token        COLON
%token        BEGINPARENTHESIS
%token        ENDPARENTHESIS
%token        COMMA
%token        LBRACKET
%token        RBRACKET
%token        EXIT
%token        INTEGER
%token        REAL
%token        ADDITION
%token        SUBTRACTION
%token        MULTIPLICATION
%token        DIVISION
%token        MODULUS
%token        LESSTHAN
%token        GREATERTHAN
%token        LESSEQUAL
%token        GREATEREQUAL
%token        EQUAL
%token        NOTEQUAL
%token        AND
%token        OR
%token        NOT
%token        ASSIGNMENT
%token        NEWLINE

%%
prog        : explist
            ;
explist     : MAIN ENDST datasect algosect END MAIN ENDST
            ;
datasect    : DATA COLON declaration
            | DATA COLON
            ;
declaration : datatype COLON varlist
            | datatype COLON varlist declaration
            ;
datatype    : REAL     { symbolType = 1;}
            | INTEGER  { symbolType = 0;}
            ;

varlist     : VARIABLE ENDST
            {
                if(insert($1, symbolType, 1))
                {
                    printf("Duplicate Variable %s\n", $1);
                    YYERROR;
                }

            }
            | VARIABLE LBRACKET INTCONSTANT RBRACKET ENDST
            {
                if(insert($1, symbolType, $3))
                {
                    printf("Duplicate Variable %s\n", $1);
                    YYERROR;
                }

            }
            | VARIABLE COMMA varlist
            {
                if(insert($1, symbolType, 1))
                {
                    printf("Duplicate Variable %s\n", $1);
                    YYERROR;
                }

            }
            | VARIABLE LBRACKET INTCONSTANT RBRACKET COMMA varlist
            {
                if(insert($1, symbolType, $3))
                {
                    printf("Duplicate Variable %s\n", $1);
                    YYERROR;
                }

            }
            ;
algosect    : ALGORITHM COLON
            ;
%%

int symbolType;

int yyerror() {
    printf("Called yyerror()%s\n", yytext);
    return 0;
}
