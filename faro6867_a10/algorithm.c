/*
 -------------------------------------
 File:    algorithm.c
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
#include "heap.h"
#include "algorithm.h"

EDGELIST* mst_prim(GRAPH *g, int start) {
	if (g == NULL)
		return NULL;

	int i, heapindex, u, n = g->order;
	int T[n], parent[n];
	for (i = 0; i < n; i++) {
		T[i] = 0;
		parent[i] = -1;
	}

	HEAPDATA hap;
	HEAP *h = new_heap(4);
	T[start] = 1;
	ADJNODE *temp = g->nodes[start]->neighbor;
	while (temp) {
		hap.key = temp->weight;
		hap.value = temp->nid;
		heap_insert(h, hap);
		parent[temp->nid] = start;
		temp = temp->next;
	}
	EDGELIST *mst = new_edgelist();
	while (h->size > 0) {
		hap = heap_extract_min(h);
		u = hap.value;
		T[u] = 1;
		insert_edge_end(mst, parent[u], u, hap.key);
		temp = g->nodes[u]->neighbor;
		while (temp) {
			heapindex = heap_search_data(h, temp->nid);
			if (heapindex >= 0) {
				if (T[temp->nid] == 0 && temp->weight < h->hda[heapindex].key) {
					heap_change_key(h, heapindex, temp->weight);
					parent[temp->nid] = u;
				}
			} else {
				if (T[temp->nid] == 0) {
					hap.key = temp->weight;
					hap.value = temp->nid;
					heap_insert(h, hap);
					parent[temp->nid] = u;
				}
			}
			temp = temp->next;
		}
	}
	return mst;
}

EDGELIST* spt_dijkstra(GRAPH *g, int start) {
	if (!g)
		return NULL;
	EDGELIST *spt = new_edgelist();
	int i, heapindex, u, n = g->order;
	int T[n], parent[n], label[n];
	HEAPDATA hap;
	for (i = 0; i < n; i++) {
		T[i] = 0;
		label[i] = 9999;
	}
	HEAP *h = new_heap(4);
	ADJNODE *temp = g->nodes[start]->neighbor;
	label[start] = 0;
	T[start] = 1;
	while (temp) {
		hap.key = temp->weight + label[start];
		hap.value = temp->nid;
		heap_insert(h, hap);
		parent[temp->nid] = start;
		temp = temp->next;
	}
	while (h->size > 0) {
		hap = heap_extract_min(h);
		u = hap.value;
		T[u] = 1;
		label[u] = hap.key;
		insert_edge_end(spt, parent[u], u, label[u] - label[parent[u]]);
		temp = g->nodes[u]->neighbor;
		while (temp) {
			heapindex = heap_search_data(h, temp->nid);
			if (heapindex >= 0) {
				if (T[temp->nid] == 0
						&& temp->weight + label[u] < h->hda[heapindex].key) {
					heap_change_key(h, heapindex, temp->weight + label[u]);
					parent[temp->nid] = u;
				}
			} else {
				if (T[temp->nid] == 0) {
					hap.key = temp->weight + label[u];
					hap.value = temp->nid;
					heap_insert(h, hap);
					parent[temp->nid] = u;
				}
			}
			temp = temp->next;
		}

	}
	return spt;
}

EDGELIST* sp_dijkstra(GRAPH *g, int start, int end) {
// your code
	if (!g)
		return NULL;

	int i, heapindex, u, n = g->order;
	int T[n], parent[n], label[n];
	HEAPDATA hap;
	for (i = 0; i < n; i++) {
		T[i] = 0;
		label[i] = 9999;
	}
	HEAP *h = new_heap(4);
	ADJNODE *temp = g->nodes[start]->neighbor;
	label[start] = 0;
	T[start] = 1;
	while (temp) {
		hap.key = temp->weight + label[start];
		hap.value = temp->nid;
		heap_insert(h, hap);
		parent[temp->nid] = start;
		temp = temp->next;
	}
	while (h->size > 0) {
		hap = heap_extract_min(h);
		u = hap.value;
		T[u] = 1;
		label[u] = hap.key;
		if (u == end)
			break;
		temp = g->nodes[u]->neighbor;
		while (temp) {
			heapindex = heap_search_data(h, temp->nid);
			if (heapindex >= 0) {
				if (T[temp->nid] == 0
						&& temp->weight + label[u] < h->hda[heapindex].key) {
					heap_change_key(h, heapindex, temp->weight + label[u]);
					parent[temp->nid] = u;
				}
			} else {
				if (T[temp->nid] == 0) {
					hap.key = temp->weight + label[u];
					hap.value = temp->nid;
					heap_insert(h, hap);
					parent[temp->nid] = u;
				}
			}
			temp = temp->next;
		}

	}
	EDGELIST *sp = new_edgelist();
	i = end;
	while (1) {
		if (i == start)
			break;
		insert_edge_start(sp, parent[i], i, label[i] - label[parent[i]]);
		i = parent[i];

	}
	return sp;
}
