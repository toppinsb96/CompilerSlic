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
int yylex();
int yyerror();
%}

%code requires
{
  #include "symbol.h"
  #include "ast.h"
  #include "y.tab.h"

  char* yytext;
  extern int symbolType;
  extern ast* root;
  ast* newExp(int type, ast *left, ast *right);
}


%union
{
    char* s;
    int d;
    float f;
    ast* a;
}

%token  <s>   VARIABLE
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
%token   <f>  FLOATCONSTANT
%token   <s>  STRCHARCONSTANT
%token        CARRIAGE
%token        ENDST
%token        COLON
%token        BEGINPAREN
%token        ENDPAREN
%token        COMMA
%token        LBRACKET
%token        RBRACKET
%token        EXIT
%token        INTEGER
%token        REAL
%token        ADD
%token        SUB
%token        MUL
%token        DIV
%token        MOD
%token        LT
%token        GT
%token        LE
%token        GE
%token        EQ
%token        NEQ
%token        AND
%token        OR
%token        NOT
%token        ASSIGNMENT
%token        NEWLINE
%token        WHITESPACE

%type    <a>  algosect;
%type    <a>  stmlist;
%type    <a>  assignment;
%type    <a>  expr;
%type    <a>  compare;
%type    <a>  logic;
%type    <a>  op;
%type    <a>  iter;
%type    <a>  factor;
%type    <a>  atom;
%type    <a>  var;
%type    <a>  print;
%type    <a>  printlst;
%type    <a>  printitem;

%%
prog        : explist
            ;
explist     : MAIN ENDST datasect algosect END MAIN ENDST { root = $4; }
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
algosect    : ALGORITHM COLON stmlist   { $$ = $3; }
            | ALGORITHM COLON           { $$ = NULL; }
            ;
stmlist     : stmlist ENDST             { $$ = $1; }
            | stmlist ENDST stmlist     { $1->next = $3; $$ = $1; }
            | assignment                { $$ = $1; }
            | print                     { $$ = $1; }
            ;
assignment  : var ASSIGNMENT expr       { $$ = newExp(ASSIGNMENT, $1, $3); }
            ;
expr        : logic
            ;
logic       : logic OR compare          { $$ = newExp(OR, $1, $3); }
            | logic AND compare         { $$ = newExp(AND, $1, $3); }
            | NOT compare               { $$ = newExp(NOT, NULL, $2); }
            | compare                   { $$ = $1; }
            ;

compare     : compare EQ op             { $$ = newExp(EQ, $1, $3); }
            | compare NEQ op            { $$ = newExp(NEQ, $1, $3); }
            | compare LT op             { $$ = newExp(LT, $1, $3); }
            | compare GT op             { $$ = newExp(GT, $1, $3); }
            | compare LE op             { $$ = newExp(LE, $1, $3); }
            | compare GE op             { $$ = newExp(GE, $1, $3); }
            | op                        { $$ = $1; }
            ;
op          : op ADD iter               { $$ = newExp(ADD, $1, $3); }
            | op SUB iter               { $$ = newExp(SUB, $1, $3); }
            | iter                      { $$ = $1; }
            ;
iter        : iter MUL factor           { $$ = newExp(MUL, $1, $3); }
            | iter DIV factor           { $$ = newExp(DIV, $1, $3); }
            | iter MOD factor           { $$ = newExp(MOD, $1, $3); }
            | factor                    { $$ = $1; }
            ;
factor      : SUB factor                { $$ = newExp(SUB, NULL, $2); }
            | BEGINPAREN expr ENDPAREN  { $$ = $2; }
            | atom                      { $$ = $1; }
            ;
atom        : var                       { $$ = $1; }
            | INTCONSTANT               {
                                          $$ = (ast *)malloc(sizeof(ast));
                                  			  $$->type = INTCONSTANT;
                                  			  $$->d = $1;
                                        }
            | FLOATCONSTANT             {
                                          $$ = (ast *)malloc(sizeof(ast));
                                  			  $$->type = FLOATCONSTANT;
                                  			  $$->f = $1;
                                        }
            ;

var         : VARIABLE                  {
                                          $$ = (ast *)malloc(sizeof(ast));
                                          $$->type = VARIABLE;
                                          $$->c = $1;
                                        }
            | VARIABLE LBRACKET expr RBRACKET
                                        {
                                          $$ = (ast *)malloc(sizeof(ast));
                                          $$->type = VARIABLE;
                                          $$->c = $1;
                                          $$->cond = $3;
                                        }
            ;
print       : PRINT printlst            {
                                          $$ = $2;
                                        }
            ;
printlst    : printitem COMMA printlst  {
                                          $1->next = $3;
                                          $$ = $1;
                                        }
            | printitem                 { $$ = $1; }
            ;
printitem   : expr                      { $$ = $1; }
            | STRCHARCONSTANT           {
                                          $$ = (ast *)malloc(sizeof(ast));
                                          $$->type = STRCHARCONSTANT;
                                          $$->c = $1;
                                        }
            | CARRIAGE                  {
                                          $$ = (ast *)malloc(sizeof(ast));
                                          $$->type = CARRIAGE;
                                        }
            ;
%%

int symbolType;

ast* newExp(int type, ast *left, ast *right)
{
	ast *result = (ast *)malloc(sizeof(ast));
	result->type = type;
	result->left = left;
	result->right = right;
	return result;
}
int yyerror()
{
    printf("Called yyerror()%s\n", yytext);
    return 0;
}
//struct SymbolTable s = lookup(VARIABLE);
//if(strcmp(s.name, NULL) == 0) { YYERROR; }
