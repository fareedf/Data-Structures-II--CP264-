/*
 -------------------------------------
 File:    bst.c
 Project: faro6867_a07
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-03-09
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

BSTNODE* bst_search(BSTNODE *root, char *key) {
	// your code
	if (root == NULL || strcmp(root->data.name, key) == 0) {
		return root;
	}

	if (strcmp(root->data.name, key) < 0) {
		return bst_search(root->right, key);
	}

	return bst_search(root->left, key);
}

void bst_insert(BSTNODE **rootp, RECORD data) {
	// your code
	if (*rootp == NULL) {
		*rootp = new_node(data);
		return;
	}

	if (strcmp((*rootp)->data.name, data.name) > 0) {
		bst_insert(&((*rootp)->left), data);
	} else {
		bst_insert(&((*rootp)->right), data);
	}
}

void bst_delete(BSTNODE **rootp, char *key) {
	// your code
	if (*rootp == NULL) {
		return;
	}

	if (strcmp((*rootp)->data.name, key) > 0) {
		bst_delete(&((*rootp)->left), key);
	} else if (strcmp((*rootp)->data.name, key) < 0) {
		bst_delete(&((*rootp)->right), key);
	} else {
		if ((*rootp)->left == NULL) {
			BSTNODE *temp = (*rootp)->right;
			free(*rootp);
			*rootp = temp;
		} else if ((*rootp)->right == NULL) {
			BSTNODE *temp = (*rootp)->left;
			free(*rootp);
			*rootp = temp;
		} else {
			BSTNODE *temp = extract_smallest_node(&((*rootp)->right));

			memcpy(&((*rootp)->data), &(temp->data), sizeof(RECORD));

			free(temp);
		}
	}
}

BSTNODE* new_node(RECORD data) {
	BSTNODE *np = (BSTNODE*) malloc(sizeof(BSTNODE));
	if (np) {
		memcpy(np, &data, sizeof(BSTNODE));
		np->left = NULL;
		np->right = NULL;
	}
	return np;
}

BSTNODE* extract_smallest_node(BSTNODE **rootp) {
	BSTNODE *p = *rootp, *parent = NULL;
	if (p) {
		while (p->left) {
			parent = p;
			p = p->left;
		}

		if (parent == NULL)
			*rootp = p->right;
		else
			parent->left = p->right;

		p->left = NULL;
		p->right = NULL;
	}

	return p;
}

void clean_bst(BSTNODE **rootp) {
	BSTNODE *root = *rootp;
	if (root) {
		if (root->left)
			clean_bst(&root->left);
		if (root->right)
			clean_bst(&root->right);
		free(root);
	}
	*rootp = NULL;
}

