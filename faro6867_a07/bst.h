/*
 -------------------------------------
 File:    bst.h
 Project: faro6867_a07
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-03-09
 -------------------------------------
 */
#ifndef BST_H_
#define BST_H_

typedef struct record {
	char name[20];
	float score;
} RECORD;

typedef struct bstnode {
	RECORD data;
	struct bstnode *left;
	struct bstnode *right;
} BSTNODE;

BSTNODE* bst_search(BSTNODE *root, char *key);

void bst_insert(BSTNODE **rootp, RECORD data);

void bst_delete(BSTNODE **rootp, char *key);

BSTNODE* new_node(RECORD data);
BSTNODE* extract_smallest_node(BSTNODE **rootp);
void clean_bst(BSTNODE **rootp);

#endif /* BST_H_ */
