#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lexer.h"
#include "Parser.h"
#include "eval.h"

cons_cell quote(cons_cell L) {
    if(L->symbol != NULL) {
            if (!strcmp(L->symbol, "()"))
                return NULL;
    }
    return L;
}
cons_cell car(cons_cell L) {
    return L->first;
}
cons_cell cdr(cons_cell L) {
    return L->rest;
}
cons_cell cons(cons_cell atom, cons_cell list) {
    //check to see if atom is false
    cons_cell one = node(NULL);
    cons_cell two = node(NULL);
    one->first = atom;
    two->first = list;
    
    if(car(one)->symbol != NULL) {
        if (!strcmp(car(one)->symbol, "#f")) {
            
            if(car(two)->symbol != NULL ) {
                if (!strcmp(car(two)->symbol, "#f"))
                {    
                    return node(NULL);
                }
            }
            return two->first;
        }  
    }
    if(car(two)->symbol!= NULL) {
        if (!strcmp(car(two)->symbol, "#f"))
    {
        return one;
    }
    }
    one->rest = car(two);
    return one;
}       

cons_cell symboll(cons_cell L) {
    if (L->symbol != NULL)
        return node("#t");
    else 
        return node("()");
}

cons_cell cellCopy(cons_cell L) {
    if (L == NULL) {
        return NULL;
    }
    if (L->symbol != NULL) {
        return node(L->symbol);
    }
    cons_cell c = node(NULL);
    if(car(L) != NULL){
        c->first = cellCopy(car(L));
    }
    if (cdr(L)!= NULL) {
        c->rest = cellCopy(cdr(L));
    }
    return c;
}

cons_cell eval(cons_cell L) {
    if (car(L) != NULL) {
        
        if (car(L) -> symbol != NULL) {
            char* symbol = car(L) -> symbol;
            if (!strcmp(symbol, "exit")) {
                printf("Have a nice day!\n");
                exit(0);
            }
            
            if(cdr(L) != NULL) {
                if (car(cdr(L)) != NULL){
                    cons_cell temp = eval(car(cdr(L)));
                    if(!strcmp(symbol, "car")) {
                        return car(temp);
                    }
                    else if (!strcmp (symbol, "cdr")){
                        return cdr(temp);
                    }
                    else if (!strcmp (symbol, "quote")){
                        return quote(car(cdr(L)));
                    }
                    else if (!strcmp (symbol, "symbol?")) {
                        return symboll(temp);
                    }
                    else if (!strcmp(symbol, "cons")) {
                        return cons(temp, eval(car(cdr(cdr(L)))));
                     }
                }
            }
        }
        else {
            eval (car(L));
            if (L->rest == NULL)
            {
                return L;
            }
        }
    }
        
    return L;
}
