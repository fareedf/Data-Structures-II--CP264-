/*
 -------------------------------------
 File:    graph.c
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
#include <string.h>
#include "queue_stack.h"
#include "graph.h"

GRAPH* new_graph(int order) {
	GRAPH *gp = malloc(sizeof(GRAPH));
	gp->nodes = malloc(order * sizeof(GNODE*));

	int i;
	for (i = 0; i < order; i++) {
		gp->nodes[i] = malloc(sizeof(GNODE));
		gp->nodes[i]->nid = i;
		strcpy(gp->nodes[i]->name, "null");
		gp->nodes[i]->neighbor = NULL;
	}

	gp->order = order;
	gp->size = 0;

	return gp;
}

void insert_edge_graph(GRAPH *g, int from, int to, int weight) {

	if (from < 0 || from >= g->order || to < 0 || to >= g->order) {
		return;
	}

	ADJNODE *ptr = g->nodes[from]->neighbor;
	while (ptr != NULL) {
		if (ptr->nid == to) {
			ptr->weight = weight;
			return;
		}
		ptr = ptr->next;
	}

	ADJNODE *node = malloc(sizeof(ADJNODE));
	node->nid = to;
	node->weight = weight;
	node->next = NULL;

	if (g->nodes[from]->neighbor == NULL) {
		g->nodes[from]->neighbor = node;
	} else {
		ptr = g->nodes[from]->neighbor;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = node;
	}

	g->size++;

}

void delete_edge_graph(GRAPH *g, int from, int to) {
// your code
	if (from < 0 || from >= g->order || to < 0 || to >= g->order) {
		return;
	}

	ADJNODE *prev = NULL;
	ADJNODE *current = g->nodes[from]->neighbor;
	while (current != NULL) {
		if (current->nid == to) {
			if (prev == NULL) {
				g->nodes[from]->neighbor = current->next;
			} else {
				prev->next = current->next;
			}
			free(current);
			g->size--;
			return;
		}
		prev = current;
		current = current->next;
	}
}

int get_edge_weight(GRAPH *g, int from, int to) {
// your code
	int weight;
	ADJNODE *find = g->nodes[from]->neighbor;
	while (find != NULL) {
		if (find->nid == to) {
			weight = find->weight;
			return weight;
		}
		find = find->next;
	}
	return INFINITY;
}

void traverse_bforder(GRAPH *g, int nid) {

	if (g == NULL)
		return;
	int n = g->order;
	int visited[n], i;
	for (i = 0; i < n; i++)
		visited[i] = 0;
	QUEUE queue = { 0 };
	GNODE *node = NULL;
	ADJNODE *anode = NULL;
	enqueue(&queue, g->nodes[nid]);
	visited[nid] = 1;
	while (queue.front) {
		node = (GNODE*) dequeue(&queue);
		printf("(%d %s) ", node->nid, node->name);
		anode = node->neighbor;
		while (anode) {
			if (visited[anode->nid] == 0) {
				enqueue(&queue, g->nodes[anode->nid]);
				visited[anode->nid] = 1;
			}
			anode = anode->next;
		}
	}
	clean_queue(&queue);
	return;

}

void traverse_dforder(GRAPH *g, int nid) {
// your code
	int n = g->order;
	int visited[n], i;
	STACK stack = { 0 };
	GNODE *node = NULL;
	ADJNODE *anode = NULL;

	for (i = 0; i < n; i++)
		visited[i] = 0;
	push(&stack, g->nodes[nid]);
	visited[nid] = 1;
	while (stack.top) {
		node = (GNODE*) pop(&stack);
		printf("(%d %s) ", node->nid, node->name);
		anode = node->neighbor;
		while (anode) {
			if (visited[anode->nid] == 0) {
				push(&stack, g->nodes[anode->nid]);
				visited[anode->nid] = 1;
			}
			anode = anode->next;
		}
	}
	clean_stack(&stack);
}

void clean_graph(GRAPH **gp) {
	int i;
	GRAPH *g = *gp;
	ADJNODE *temp, *ptr;
	for (i = 0; i < g->order; i++) {
		ptr = g->nodes[i]->neighbor;
		while (ptr != NULL) {
			temp = ptr;
			ptr = ptr->next;
			free(temp);
		}
		free(g->nodes[i]);
	}
	free(g->nodes);
	free(g);
	*gp = NULL;
}

void display_graph(GRAPH *g) {
	if (g) {
		printf("order %d ", g->order);
		printf("size %d ", g->size);
		printf("(from to weight) ");
		int i;
		ADJNODE *ptr;
		for (i = 0; i < g->order; i++) {
			//printf("\n%d:", g->nodes[i]->nid);
			ptr = g->nodes[i]->neighbor;
			while (ptr != NULL) {
				printf("(%d %d %d) ", i, ptr->nid, ptr->weight);
				ptr = ptr->next;
			}
		}
	}
}
