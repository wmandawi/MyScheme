/***************************************************************
 File: parser.h
 ----------------
***************************************************************/
 #ifndef PARSER
 #define PARSER
 #include <stdlib.h>
 #include "lexer.h"

typedef struct conscell {
    char* symbol;
    struct conscell *first;
    struct conscell *rest;
}*cons_cell;

char token[20];
 cons_cell start();
 void printList(cons_cell node);

 #endif