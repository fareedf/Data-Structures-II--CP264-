/*
 -------------------------------------
 File:    avl.h
 Project: faro6867_a08
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-03-16
 -------------------------------------
 */
#ifndef AVL_H_
#define AVL_H_

typedef struct record {
	char name[20];
	float score;
} RECORD;

typedef struct avlnode {
	RECORD data;
	int height;
	struct avlnode *left;
	struct avlnode *right;
} AVLNODE;

void avl_insert(AVLNODE **rootp, RECORD data);

void avl_delete(AVLNODE **rootp, char *key);

AVLNODE* avl_search(AVLNODE *root, char *name);

void clean_avl(AVLNODE **rootp);

int height(AVLNODE *root);

int balance_factor(AVLNODE *np);

AVLNODE* rotate_left(AVLNODE *np);

AVLNODE* rotate_right(AVLNODE *root);

#endif /* AVL_H_ */
