/*
 -------------------------------------
 File:    edgelist.c
 Project: faro6867_a10
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-04-03
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "edgelist.h"

EDGELIST* new_edgelist() {
	EDGELIST *tp = malloc(sizeof(EDGELIST));
	tp->size = 0;
	tp->start = NULL;
	tp->end = NULL;
	return tp;
}

void insert_edge_end(EDGELIST *g, int from, int to, int weight) {
// your code
	EDGENODE *node = malloc(sizeof(EDGENODE));
	node->from = from;
	node->to = to;
	node->weight = weight;
	node->next = NULL;

	if (g->size == 0) {
		g->start = node;
		g->end = node;
	} else {
		g->end->next = node;
		g->end = node;
	}

	g->size += 1;
}

void insert_edge_start(EDGELIST *g, int from, int to, int weight) {
// your code;
	EDGENODE *node = malloc(sizeof(EDGENODE));
	node->from = from;
	node->to = to;
	node->weight = weight;

	if (g->size == 0) {
		g->start = node;
		g->end = node;
		node->next = NULL;
	} else {
		node->next = g->start;
		g->start = node;
	}

	g->size += 1;
}

void delete_edge(EDGELIST *g, int from, int to) {
// your code
	EDGENODE *prev = NULL;
	EDGENODE *current = g->start;

	if (g->size == 0) {
		return;
	} else if (g->size == 1) {
		g->start = NULL;
		g->end = NULL;
	} else {
		while (current != NULL) {
			if (current->from == from && current->to == to) {
				if (prev == NULL) {
					// Edge is the first node in the list
					g->start = current->next;
				} else {
					prev->next = current->next;
					if (g->end == current) {
						g->end = prev;
					}
				}

				free(current);
				g->size--;
				return;
			}
			prev = current;
			current = current->next;
		}
	}
}

int weight_edgelist(EDGELIST *g) {
// your code
	int weight = 0;
	if (g->size == 0) {
		return weight;
	} else {
		EDGENODE *current = g->start;
		while (current != NULL) {
			weight += current->weight;
			current = current->next;
		}
	}
	return weight;
}

void clean_edgelist(EDGELIST **gp) {
	EDGELIST *g = *gp;
	EDGENODE *temp, *p = g->start;
	while (p) {
		temp = p;
		p = p->next;
		free(temp);
	}
	free(g);
	*gp = NULL;
}

void display_edgelist(EDGELIST *g) {
	if (g == NULL)
		return;
	printf("size %d ", g->size);
	printf("(from to weight) ");
	EDGENODE *p = g->start;
	while (p) {
		printf("(%d %d %d) ", p->from, p->to, p->weight);
		p = p->next;
	}
}
