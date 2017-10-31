/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 20 "parser.yy" /* yacc.c:1915  */

  #include "symbol.h"
  #include "ast.h"
  #include "y.tab.h"

  char* yytext;
  extern int symbolType;
  extern ast* root;
  ast* newExp(int type, ast *left, ast *right);

#line 55 "y.tab.h" /* yacc.c:1915  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VARIABLE = 258,
    MAIN = 259,
    END = 260,
    DATA = 261,
    ALGORITHM = 262,
    WHILE = 263,
    COUNTING = 264,
    UPWARD = 265,
    DOWNWARD = 266,
    TO = 267,
    IF = 268,
    ELSE = 269,
    READ = 270,
    PRINT = 271,
    INTCONSTANT = 272,
    FLOATCONSTANT = 273,
    STRCHARCONSTANT = 274,
    CARRIAGE = 275,
    ENDST = 276,
    COLON = 277,
    BEGINPAREN = 278,
    ENDPAREN = 279,
    COMMA = 280,
    LBRACKET = 281,
    RBRACKET = 282,
    EXIT = 283,
    INTEGER = 284,
    REAL = 285,
    ADD = 286,
    SUB = 287,
    MUL = 288,
    DIV = 289,
    MOD = 290,
    LT = 291,
    GT = 292,
    LE = 293,
    GE = 294,
    EQ = 295,
    NEQ = 296,
    AND = 297,
    OR = 298,
    NOT = 299,
    ASSIGNMENT = 300,
    NEWLINE = 301,
    WHITESPACE = 302
  };
#endif
/* Tokens.  */
#define VARIABLE 258
#define MAIN 259
#define END 260
#define DATA 261
#define ALGORITHM 262
#define WHILE 263
#define COUNTING 264
#define UPWARD 265
#define DOWNWARD 266
#define TO 267
#define IF 268
#define ELSE 269
#define READ 270
#define PRINT 271
#define INTCONSTANT 272
#define FLOATCONSTANT 273
#define STRCHARCONSTANT 274
#define CARRIAGE 275
#define ENDST 276
#define COLON 277
#define BEGINPAREN 278
#define ENDPAREN 279
#define COMMA 280
#define LBRACKET 281
#define RBRACKET 282
#define EXIT 283
#define INTEGER 284
#define REAL 285
#define ADD 286
#define SUB 287
#define MUL 288
#define DIV 289
#define MOD 290
#define LT 291
#define GT 292
#define LE 293
#define GE 294
#define EQ 295
#define NEQ 296
#define AND 297
#define OR 298
#define NOT 299
#define ASSIGNMENT 300
#define NEWLINE 301
#define WHITESPACE 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 33 "parser.yy" /* yacc.c:1915  */

    char* s;
    int d;
    float f;
    ast* a;

#line 168 "y.tab.h" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
