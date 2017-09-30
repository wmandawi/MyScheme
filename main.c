/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Wurood Mandawi
 *
 * Created on March 2, 2017, 10:57 AM
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Parser.h"
#include "lexer.h"
#include "eval.h"

/*
 * 
 */
 main() {
 cons_cell node(char* symb);
 char token[20]; 
 startTokens(20);
 printf("A prototype evaluator for Scheme.\n");
 printf("Type Scheme expressions using quote,\n");
 printf("car, cdr, cons and symbol?.\n");
 printf("The function call (exit) quits.\n");
 printf("\n");
 
 printf("scheme> ");
    while (1){
        printList(eval(start()));
        printf("\n\nscheme> ");
    }
 
    }



