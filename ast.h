/*
 * ========================================================================
 *
 * ast.h
 *
 * Programmer --- Brandon Toppins
 *
 * ========================================================================
 */
#ifndef AST_H_
#define AST_H_
#include "symbol.h"

typedef struct ast {
    struct ast *left;
    struct ast *right;
    struct ast *next;

    int type;

    int d;
    float f;
    char* c;

    struct ast *cond;
} ast;

#endif
