/*
 -------------------------------------
 File:    dllist.c
 Project: faro6867_a05
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-02-17
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

NODE* new_node(char data) {
	NODE *new = (NODE*) malloc(sizeof(NODE));

	new->data = data;
	new->prev = NULL;
	new->next = NULL;

	return new;
}

void dll_insert_start(DLL *dllp, NODE *np) {
	if (dllp->start == NULL) {
		np->prev = NULL;
		np->next = NULL;
		dllp->start = np;
		dllp->end = np;
	} else {
		np->prev = NULL;
		np->next = dllp->start;
		dllp->start->prev = np;
		dllp->start = np;
	}
	dllp->length++;
}

void dll_insert_end(DLL *dllp, NODE *np) {
	if (dllp->end == NULL) {
		np->prev = NULL;
		np->next = NULL;
		dllp->start = np;
		dllp->end = np;
	} else {
		np->next = NULL;
		np->prev = dllp->end;
		dllp->end->next = np;
		dllp->end = np;
	}
	dllp->length++;
}

void dll_delete_start(DLL *dllp) {
	if (dllp->start != NULL) {
		NODE *temp = dllp->start;
		dllp->start = dllp->start->next;
		if (dllp->start != NULL) {
			dllp->start->prev = NULL;
		} else {
			dllp->end = NULL;
		}
		free(temp);
		dllp->length--;
	}
}

void dll_delete_end(DLL *dllp) {
	if (dllp->end != NULL) {
		NODE *temp = dllp->end;
		dllp->end = dllp->end->prev;
		if (dllp->end != NULL) {
			dllp->end->next = NULL;
		} else {
			dllp->start = NULL;
		}
		free(temp);
		dllp->length--;
	}
}

void dll_clean(DLL *dllp) {
	while (dllp->start != NULL) {
		NODE *temp = dllp->start;
		dllp->start = dllp->start->next;
		free(temp);
	}
	dllp->end = NULL;
	dllp->length = 0;
}
