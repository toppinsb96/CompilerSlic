%{
/*
 * ========================================================================
 *
 * scanner.l -- CS4223 Checkpoint #2
 *
 * Programmer --- Brandon Toppins
 *
 * ========================================================================
 */
  #include <stdio.h>
  #include "y.tab.h"
%}

%%

[Mm][Aa][Ii][Nn]                                      { return(MAIN); }
[Ee][Nn][Dd]                                          { return(END); }
[Dd][Aa][Tt][Aa]                                      { return(DATA); }
[Aa][Ll][Gg][Oo][Rr][Ii][Tt][Hh][Mm]                  { return(ALGORITHM); }
[Ww][Hh][Ii][Ll][Ee]                                  { return(WHILE); }
[Cc][Oo][Uu][Nn][Tt][Ii][Nn][Gg]                      { return(COUNTING); }
[Uu][Pp][Ww][Aa][Rr][Dd]                              { return(UPWARD); }
[Dd][Oo][Ww][Nn][Ww][Aa][Rr][Dd]                      { return(DOWNWARD); }
[Tt][Oo]                                              { return(TO); }
[Ii][Ff]                                              { return(IF); }
[Ee][Ll][Ss][Ee]                                      { return(ELSE); }
[Rr][Ee][Aa][Dd]                                      { return(READ); }
[Pp][Rr][Ii][Nn][Tt]                                  { return(PRINT); }
[0-9]+                                                {
                                                          yylval.d = atoi(yytext);
                                                          return(INTCONSTANT);
                                                      }
[-+]?([0-9]\.[0-9])|([0-9]+(\.[0-9]+)?[Ee][-+][0-9]+) { return(FLOATCONSTANT); }
\"([\^]|\"\")*\"                                      { return(STRCHARCONSTANT); }
[\t ]+                                                { }
!                                                     { return(CARRIAGE); }
#.*                                                   { }
;                                                     { return(ENDST); }
:                                                     { return(COLON); }
\(                                                    { return(BEGINPARENTHESIS); }
\)                                                    { return(ENDPARENTHESIS); }
,                                                     { return(COMMA); }
\[                                                    { return(LBRACKET); }
\]                                                    { return(RBRACKET); }
[Ee][Xx][Ii][Tt]                                      { return(EXIT); }
[Ii][Nn][Tt][Ee][Gg][Ee][Rr]                          { return(INTEGER); }
[Rr][Ee][Aa][Ll]                                      { return(REAL); }
[A-Za-z][A-Za-z0-9]*                                  {
                                                          yylval.str = strdup(yytext);
                                                          return(VARIABLE);
                                                      }
"+"                                                   { return(ADDITION); }
"-"                                                   { return(SUBTRACTION); }
"*"                                                   { return(MULTIPLICATION); }
"/"                                                   { return(DIVISION); }
"%"                                                   { return(MODULUS); }
"<"                                                   { return(LESSTHAN); }
">"                                                   { return(GREATERTHAN); }
"<="                                                  { return(LESSEQUAL); }
">="                                                  { return(GREATEREQUAL); }
"="                                                   { return(EQUAL); }
"<>"                                                  { return(NOTEQUAL); }
"&"                                                   { return(AND); }
"|"                                                   { return(OR); }
"~"                                                   { return(NOT); }
":="                                                  { return(ASSIGNMENT); }
\n                                                    { }
.                                                     { }

%%
