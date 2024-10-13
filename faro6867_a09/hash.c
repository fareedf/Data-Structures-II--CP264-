/*
 -------------------------------------
 File:    hash.c
 Project: faro6867_a09
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-03-23
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

HASHNODE* hashtable_search(HASHTABLE *ht, char *key) {
	int index = hash(key, ht->size);
	HASHNODE *current = ht->hna[index];
	while (current != NULL) {
		if (strcmp(current->key, key) == 0) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}

int hashtable_insert(HASHTABLE *ht, char *key, int value) {
	int index = hash(key, ht->size);
	HASHNODE *current = ht->hna[index];
	HASHNODE *prev = NULL;
	while (current != NULL) {
		if (strcmp(current->key, key) == 0) {
			current->value = value; // Update value
			return 0;
		}
		prev = current;
		current = current->next;
	}
	HASHNODE *new_node = (HASHNODE*) malloc(sizeof(HASHNODE));
	if (new_node == NULL) {
		return -1;
	}
	strcpy(new_node->key, key);
	new_node->value = value;
	new_node->next = NULL;
	if (prev == NULL) {
		ht->hna[index] = new_node;
	} else {
		prev->next = new_node;
	}

	ht->count++;
	return 1;
}

int hashtable_delete(HASHTABLE *ht, char *key) {
// your code
	int index = hash(key, ht->size);
	HASHNODE *current = ht->hna[index];
	HASHNODE *prev = NULL;

	while (current != NULL) {
		if (strcmp(current->key, key) == 0) {
			if (prev == NULL) {
				ht->hna[index] = current->next;
			} else {
				prev->next = current->next;
			}
			free(current);
			ht->count--;
			return 1;
		}
		prev = current;
		current = current->next;
	}
	return 0;

}

int hash(char *key, int size) {
	unsigned int hash = 0;
	while (*key) {
		hash += *key++;
	}
	return hash % size;
}

HASHTABLE* new_hashtable(int size) {
	HASHTABLE *ht = (HASHTABLE*) malloc(sizeof(HASHTABLE));
	ht->hna = (HASHNODE**) malloc(sizeof(HASHNODE**) * size);
	int i;
	for (i = 0; i < size; i++)
		*(ht->hna + i) = NULL;

	ht->size = size;
	ht->count = 0;
	return ht;
}

void hashtable_clean(HASHTABLE **htp) {
	if (*htp == NULL)
		return;
	HASHTABLE *ht = *htp;
	HASHNODE *p, *temp;
	int i;
	for (i = 0; i < ht->size; i++) {
		p = ht->hna[i];
		while (p) {
			temp = p;
			p = p->next;
			free(temp);
		}
		ht->hna[i] = NULL;
	}
	free(ht->hna);
	ht->hna = NULL;
	*htp = NULL;
}
