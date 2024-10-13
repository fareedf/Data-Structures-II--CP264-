/*
 -------------------------------------
 File:    tree.c
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
#include "queue_stack.h"
#include "tree.h"

TPROPS tree_property(TNODE *root) {
	// your code
	TPROPS r = { 0, 0 };
	if (root) {
		TPROPS lp = tree_property(root->left);
		TPROPS rp = tree_property(root->right);
		r.order = 1 + lp.order + rp.order;
		r.height = 1 + (lp.height > rp.height ? lp.height : rp.height);
	}
	return r;
}

void preorder(TNODE *root) {
	// your code
	if (root) {
		printf("%c ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(TNODE *root) {
	// your code
	if (root) {
		inorder(root->left);
		printf("%c ", root->data);
		inorder(root->right);
	}
}

void postorder(TNODE *root) {
	// your code
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%c ", root->data);
	}
}

void bforder(TNODE *root) {
	// your code
	if (root) {
		QUEUE queue = { 0 };
		enqueue(&queue, root);
		while (queue.front) {
			TNODE *tn = (TNODE*) dequeue(&queue);
			printf("%c ", tn->data);
			if (tn->left)
				enqueue(&queue, tn->left);
			if (tn->right)
				enqueue(&queue, tn->right);
		}
		clean_queue(&queue);
	}
}

TNODE* bfs(TNODE *root, char val) {
	// your code
	TNODE *r = NULL;
	if (root) {
		QUEUE queue = { 0 };
		enqueue(&queue, root);
		while (queue.front) {
			TNODE *tnp = (TNODE*) dequeue(&queue);
			if (tnp->data == val) {
				r = tnp;
				break;
			}
			if (tnp->left)
				enqueue(&queue, tnp->left);
			if (tnp->right)
				enqueue(&queue, tnp->right);
		}
		clean_queue(&queue);
	}
	return r;
}

TNODE* dfs(TNODE *root, char val) {
	// your code
	TNODE *r = NULL;
	if (root) {
		STACK stack = { 0 };
		push(&stack, root);
		while (stack.top) {
			TNODE *p = (TNODE*) pop(&stack);
			if (p->data == val) {
				r = p;
				break;
			}
			if (p->right)
				push(&stack, p->right);
			if (p->left)
				push(&stack, p->left);
		}
		clean_stack(&stack);
	}
	return r;
}

TNODE* new_node(char val) {
	TNODE *np = (TNODE*) malloc(sizeof(TNODE));
	if (np != NULL) {
		np->data = val;
		np->left = NULL;
		np->right = NULL;
	}
	return np;
}

void clean_tree(TNODE **rootp) {
	TNODE *p = *rootp;
	if (p) {
		if (p->left)
			clean_tree(&p->left);
		if (p->right)
			clean_tree(&p->right);
		free(p);
	}
	*rootp = NULL;
}

void insert_tree(TNODE **rootp, char val) {
	if (*rootp == NULL) {
		*rootp = new_node(val);
	} else {
		QUEUE queue = { 0 };
		TNODE *p;
		enqueue(&queue, *rootp);
		while (queue.front) {
			p = dequeue(&queue);
			if (p->left == NULL) {
				p->left = new_node(val);
				break;
			} else {
				enqueue(&queue, p->left);
			}

			if (p->right == NULL) {
				p->right = new_node(val);
				break;
			} else {
				enqueue(&queue, p->right);
			}
		}
	}
}

