/*
 -------------------------------------
 File:    hash.h
 Project: faro6867_a09
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-03-23
 -------------------------------------
 */
#ifndef HASH_H_
#define HASH_H_

typedef struct {
	char key[20];
	int value;
} HASHDATA;

typedef struct hashnode {
	char key[20];
	int value;
	struct hashnode *next;
} HASHNODE;

typedef struct hashtable {
	HASHNODE **hna;
	int size;
	int count;
} HASHTABLE;

int hash(char *key, int size);

HASHTABLE* new_hashtable(int size);

int hashtable_insert(HASHTABLE *ht, char *key, int value);

HASHNODE* hashtable_search(HASHTABLE *ht, char *key);

int hashtable_delete(HASHTABLE *ht, char *key);

void hashtable_clean(HASHTABLE **ht);

#endif /* HASH_H_ */
