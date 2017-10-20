/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
     BEGINPARENTHESIS = 278,
     ENDPARENTHESIS = 279,
     COMMA = 280,
     LBRACKET = 281,
     RBRACKET = 282,
     EXIT = 283,
     INTEGER = 284,
     REAL = 285,
     ADDITION = 286,
     SUBTRACTION = 287,
     MULTIPLICATION = 288,
     DIVISION = 289,
     MODULUS = 290,
     LESSTHAN = 291,
     GREATERTHAN = 292,
     LESSEQUAL = 293,
     GREATEREQUAL = 294,
     EQUAL = 295,
     NOTEQUAL = 296,
     AND = 297,
     OR = 298,
     NOT = 299,
     ASSIGNMENT = 300,
     NEWLINE = 301
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
#define BEGINPARENTHESIS 278
#define ENDPARENTHESIS 279
#define COMMA 280
#define LBRACKET 281
#define RBRACKET 282
#define EXIT 283
#define INTEGER 284
#define REAL 285
#define ADDITION 286
#define SUBTRACTION 287
#define MULTIPLICATION 288
#define DIVISION 289
#define MODULUS 290
#define LESSTHAN 291
#define GREATERTHAN 292
#define LESSEQUAL 293
#define GREATEREQUAL 294
#define EQUAL 295
#define NOTEQUAL 296
#define AND 297
#define OR 298
#define NOT 299
#define ASSIGNMENT 300
#define NEWLINE 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 24 "parser.yy"
{
    char* str;
    int d;
}
/* Line 1529 of yacc.c.  */
#line 146 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

