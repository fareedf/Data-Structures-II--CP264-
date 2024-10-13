/*
 -------------------------------------
 File:    myrecord_avl.c
 Project: faro6867_a08
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-03-16
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "avl.h"
#include "myrecord_avl.h"

void merge_avl(AVLNODE **dest_rootp, AVLNODE **source_rootp) {
// your code
	AVLNODE *source_root = *source_rootp;
	if (source_root != NULL) {
		avl_insert(dest_rootp, source_root->data);
		merge_avl(dest_rootp, &(source_root->left));
		merge_avl(dest_rootp, &(source_root->right));
		free(source_root);
		*source_rootp = NULL;
	}
}

void merge_avlds(AVLDS *dest, AVLDS *source) {
// your code
	merge_avl(&(dest->root), &(source->root));
	dest->count += source->count;

	float dest_mean = dest->mean;
	float source_mean = source->mean;
	float dest_stddev = dest->stddev;
	float source_stddev = source->stddev;
	int dest_count = dest->count;
	int source_count = source->count;

	if (dest_count == 0) {
		dest->mean = 0;
		dest->stddev = 0;
	} else if (source_count != 0) {
		float total_mean = (dest_mean * dest_count + source_mean * source_count)
				/ (dest_count + source_count);
		float total_variance = (dest_stddev * dest_stddev * dest_count
				+ source_stddev * source_stddev * source_count
				+ dest_mean * dest_mean * dest_count
				+ source_mean * source_mean * source_count)
				/ (dest_count + source_count) - total_mean * total_mean;
		dest->mean = total_mean;
		dest->stddev = sqrt(total_variance);
	}

	clean_avlds(source);

}

void clean_avlds(AVLDS *ds) {
	clean_avl(&ds->root);
	ds->count = 0;
	ds->mean = 0;
	ds->stddev = 0;
}

// the following functions are adapted from a7q3
void add_record(AVLDS *tree, RECORD data) {
	if (avl_search(tree->root, data.name) == NULL) {
		avl_insert(&(tree->root), data);
		int count = tree->count;
		float mean = tree->mean;
		float stddev = tree->stddev;
		tree->count = count + 1;
		tree->mean = (mean * count + data.score) / (count + 1.0);
		tree->stddev = sqrt(
				data.score * data.score / (count + 1.0)
						+ (stddev * stddev + mean * mean)
								* (count / (count + 1.0))
						- tree->mean * tree->mean);
	} else {
		printf("record exits");
	}
}

void remove_record(AVLDS *tree, char *name) {
	AVLNODE *np = NULL;
	if ((np = avl_search(tree->root, name)) != NULL) {
		float score = np->data.score;
		avl_delete(&(tree->root), name);
		float count = tree->count;
		float mean = tree->mean;
		float stddev = tree->stddev;
		tree->count = count - 1;
		if (count >= 3) {
			tree->mean = (mean * count - score) / (count - 1.0);
			tree->stddev = sqrt(
					(stddev * stddev + mean * mean) * (count / (count - 1.0))
							- score * score / (count - 1.0)
							- tree->mean * tree->mean);
		} else if (count == 2) {
			tree->mean = mean * count - score;
			tree->stddev = 0;
		} else {
			tree->mean = 0;
			tree->stddev = 0;
		}
	} else {
		printf("record does not exit");
	}
}
