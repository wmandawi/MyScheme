/****************************************************************
 File: parser.c
 ----------------
 This file implements the parser interface given in parser.h
 ****************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lexer.h"
#include "Parser.h"
#include "eval.h"

char token[20];

//create new node take a char and return list pointer to cons cell
cons_cell node(char* symbol){
    cons_cell init = (cons_cell) malloc(sizeof(struct conscell));
    if(symbol == NULL) 
        init->symbol = NULL;
    else {
        init->symbol = malloc (sizeof(char)*strlen(symbol)+ 1);
        strcpy(init-> symbol, symbol);
    }
    init -> first = NULL;
    init -> rest = NULL;
    return init;
}
//print the level

//print list helper
void printL(cons_cell L, int s) {
    if(L != NULL) {
        if (L->symbol != NULL) {
            printf("%s", L->symbol);
        }
        else {
            if (s) {
                printf("(");
            }
            printL(L->first, 1);
            if (L->rest == NULL) {
                printf(")");
            }
            else {
                printf(" ");
                printL(L->rest, 0);
            }
        }
    }
}
void printList(cons_cell L){
    return printL(L, 1);
    
}
cons_cell S_exp(int level) {
    cons_cell local;
    cons_cell temp;
    
    if(!strcmp(token,"(")) 
    { //check is (
        local = node(NULL);
        strcpy(token, getToken());
        local->first = S_exp(level+1);
        temp = local;
      
        while(strcmp(token, ")")) 
        {  
            //temp -> rest = allocate a new node
            temp->rest = node(NULL);
            temp = temp -> rest;
            temp->first = S_exp(level + 1);
          
        }
        temp -> rest = NULL;
        //check level 
        if(level != 0)
            strcpy(token, getToken());
    }   
    else if (!strcmp(token, "#f"))
    {
        local = node("#f");
        if(level != 0)
            strcpy(token, getToken());
    }
     
     else if (!strcmp(token, "()"))
     {
        local = node("()");
        if(level != 0)
            strcpy(token, getToken());
    }
    else if (!strcmp(token, "#t"))
     {
        local = node("#t");
        if(level != 0)
            strcpy(token, getToken());
    }
     else if( !strcmp(token,"\'") ) 
     {
                local = node(NULL);
		local->first = node("quote"); 
		temp = local;
		strcpy(token, getToken());	   
		temp->rest = node(NULL);
		temp = temp->rest;
        temp->first = S_exp(level);
     }
     else if (!strcmp(token,"(exit)")) 
    {        
	printf("Have a nice day!\n");
	exit(0);
    }
     else {
        local = node(token);
        if(level != 0)
            strcpy(token, getToken());
    }
    return local;
}    

cons_cell start() {
    startTokens(20);
    strcpy(token, getToken());
    return S_exp (0);
}
   
        
