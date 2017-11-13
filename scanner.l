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
  #include <string.h>
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
[-+]?([0-9]\.[0-9])|([0-9]+(\.[0-9]+)?[Ee][-+][0-9]+) {
                                                          yylval.f = atof(yytext);
                                                          return(FLOATCONSTANT);
                                                      }
\"([^\n\r\"]|\"\")*\"                                 {
                                                        char* cpytext = yytext;
                                                        cpytext++;
                                                        int len = strlen(cpytext);
                                                        yylval.s = strdup(yytext);
                                                        strncpy(yylval.s, cpytext, len-1);
                                                        yylval.s[len-1] = '\0';
                                                        yylval.s = strdup(yytext);

                                                        return(STRCHARCONSTANT);
                                                      }
[\t ]+                                                { }
!                                                     { return(CARRIAGE); }
#.*                                                   { }
;                                                     { return(ENDST); }
:                                                     { return(COLON); }
\(                                                    { return(BEGINPAREN); }
\)                                                    { return(ENDPAREN); }
,                                                     { return(COMMA); }
\[                                                    { return(LBRACKET); }
\]                                                    { return(RBRACKET); }
[Ee][Xx][Ii][Tt]                                      { return(EXIT); }
[Ii][Nn][Tt][Ee][Gg][Ee][Rr]                          { return(INTEGER); }
[Rr][Ee][Aa][Ll]                                      { return(REAL); }
[A-Za-z][A-Za-z0-9]*                                  {
                                                          yylval.s = strdup(yytext);
                                                          return(VARIABLE);
                                                      }
"+"                                                   { return(ADD); }
"-"                                                   { return(SUB); }
"*"                                                   { return(MUL); }
"/"                                                   { return(DIV); }
"%"                                                   { return(MOD); }
"<"                                                   { return(LT); }
">"                                                   { return(GT); }
"<="                                                  { return(LE); }
">="                                                  { return(GE); }
"="                                                   { return(EQ); }
"<>"                                                  { return(NEQ); }
"&"                                                   { return(AND); }
"|"                                                   { return(OR); }
"~"                                                   { return(NOT); }
":="                                                  { return(ASSIGNMENT); }
\n                                                    { }
.                                                     { return(WHITESPACE); }

%%
