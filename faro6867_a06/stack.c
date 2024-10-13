/*
 -------------------------------------
 File:    stack.c
 Project: faro6867_a06
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-02-27
 -------------------------------------
 */

#include <stdio.h>
#include "stack.h"

void push(STACK *sp, NODE *np) {
// your code
	np->next = sp->top;
	sp->top = np;
	sp->length += 1;
}

NODE* pop(STACK *sp) {
// your code
	if (sp->top == NULL) {
		return NULL;
	} else {
		NODE *temp = sp->top;
		sp->top = sp->top->next;
		sp->length -= 1;
		return temp;
	}
}

void clean_stack(STACK *sp) {
	clean(&(sp->top));
	sp->top = NULL;
	sp->length = 0;
}
