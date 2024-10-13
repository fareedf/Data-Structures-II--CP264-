/*
 -------------------------------------
 File:    myrecord_sllist.c
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
#include <string.h>
#include "myrecord_sllist.h"

NODE* sll_search(SLL *sllp, char *name) {
	NODE *np = sllp->start;
	while (np != NULL) {
		if (strcmp(np->data.name, name) == 0) {
			return np;
		}
		np = np->next;
	}
	return NULL;
}

void sll_insert(SLL *sllp, char *name, float score) {
	NODE *np = (NODE*) malloc(sizeof(NODE));
	strcpy(np->data.name, name);
	np->data.score = score;
	np->next = NULL;

	NODE *prev = NULL, *p = sllp->start;
	while (p != NULL && strcmp(p->data.name, name) < 0) {
		prev = p;
		p = p->next;
	}
	if (prev == NULL) {
		np->next = sllp->start;
		sllp->start = np;
	} else {
		prev->next = np;
		np->next = p;
	}
	sllp->length++;
}

int sll_delete(SLL *sllp, char *name) {
	NODE *prev = NULL, *p = sllp->start;
	while (p != NULL && strcmp(p->data.name, name) != 0) {
		prev = p;
		p = p->next;
	}
	if (p == NULL) {
		return 0;
	}
	if (prev == NULL) {
		sllp->start = p->next;
	} else {
		prev->next = p->next;
	}
	free(p);
	sllp->length--;
	return 1;
}

void sll_clean(SLL *sllp) {
	NODE *temp, *ptr = sllp->start;
	while (ptr != NULL) {
		temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
	sllp->start = NULL;
	sllp->length = 0;
}
