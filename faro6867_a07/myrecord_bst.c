/*
 -------------------------------------
 File:    myrecord_bst.c
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
#include <math.h>
#include "queue_stack.h"
#include "bst.h"
#include "myrecord_bst.h"

void add_record_aux(BSTNODE **node, RECORD record, BSTDS *ds) {
	if (*node == NULL) {
		*node = (BSTNODE*) malloc(sizeof(BSTNODE));
		if (*node == NULL) {
			return;
		}
		(*node)->data = record;
		(*node)->left = (*node)->right = NULL;

		ds->count++;
		float oldMean = ds->mean;
		ds->mean += (record.score - ds->mean) / ds->count;
		ds->stddev = sqrt(
				((ds->stddev * ds->stddev) * (ds->count - 1)
						+ (record.score - oldMean) * (record.score - ds->mean))
						/ ds->count);
	} else if (record.score < (*node)->data.score) {
		add_record_aux(&((*node)->left), record, ds);
	} else {
		add_record_aux(&((*node)->right), record, ds);
	}

}
void add_record(BSTDS *ds, RECORD record) {
	// your code
	if (ds->root == NULL) {
		ds->root = (BSTNODE*) malloc(sizeof(BSTNODE));
		if (ds->root == NULL) {
			return;
		}
		ds->root->data = record;
		ds->root->left = ds->root->right = NULL;
		ds->count = 1;
		ds->mean = record.score;
		ds->stddev = 0;
	} else {
		add_record_aux(&(ds->root), record, ds);
	}
}

void remove_record_aux(BSTDS *ds, float removedValue) {
	if (ds->count <= 1) {
		ds->count = 0;
		ds->mean = 0;
		ds->stddev = 0;
		return;
	}

	float oldMean = ds->mean;
	float oldStdDev = ds->stddev;
	int oldCount = ds->count;
	ds->count--;
	float newMean = oldMean + (oldMean - removedValue) / ds->count;

	float sum = oldCount * (oldStdDev * oldStdDev + oldMean * oldMean);
	sum -= removedValue * removedValue;
	float newStdDev = sqrt((sum - ds->count * newMean * newMean) / ds->count);

	ds->mean = newMean;
	ds->stddev = newStdDev;

}

void remove_record(BSTDS *ds, char *name) {
	// your code
	BSTNODE *nodeToRemove = bst_search(ds->root, name);
	if (nodeToRemove == NULL) {
		return;
	}
	remove_record_aux(ds, nodeToRemove->data.score);

	bst_delete(&(ds->root), nodeToRemove->data.name);

}

void clean_bstds(BSTDS *ds) {
	clean_bst(&ds->root);
	ds->count = 0;
	ds->mean = 0;
	ds->stddev = 0;
}

