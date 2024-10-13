/*
 -------------------------------------
 File:    heap.c
 Project: faro6867_a09
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-03-23
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

int cmp(KEYTYPE a, KEYTYPE b) {
	int r = 0;
	if (a < b)
		r = -1;
	else if (a > b)
		r = 1;
	return r;
}

HEAP* new_heap(int capacity) {
	HEAP *hp = (HEAP*) malloc(sizeof(HEAP));
	if (hp == NULL)
		return NULL;
	hp->hda = (HEAPDATA*) malloc(sizeof(HEAPDATA) * capacity);
	if (hp->hda == NULL) {
		free(hp);
		return NULL;
	};
	hp->capacity = capacity;
	hp->size = 0;
	return hp;
}

int heapify_up(HEAPDATA *hda, int index) {
	while (index > 0) {
		int parent = (index - 1) / 2;
		if (cmp(hda[parent].key, hda[index].key) > 0) {
			HEAPDATA temp = hda[index];
			hda[index] = hda[parent];
			hda[parent] = temp;
			index = parent;
		} else {
			break;
		}
	}
	return 0;
}

int heapify_down(HEAPDATA *hda, int n, int index) {
	while (index < n) {
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		int smallest = index;

		if (left < n && cmp(hda[left].key, hda[smallest].key) < 0) {
			smallest = left;
		}
		if (right < n && cmp(hda[right].key, hda[smallest].key) < 0) {
			smallest = right;
		}
		if (smallest != index) {
			HEAPDATA temp = hda[index];
			hda[index] = hda[smallest];
			hda[smallest] = temp;
			index = smallest;
		} else {
			break;
		}
	}
	return 0;
}

void heap_insert(HEAP *heap, HEAPDATA new_node) {
	if (heap->size == heap->capacity) {
		heap->capacity *= 2;
		heap->hda = realloc(heap->hda, sizeof(HEAPDATA) * heap->capacity);
		if (!heap->hda) {
			exit(EXIT_FAILURE);
		}
	}

	int i = heap->size++;
	while (i && cmp(new_node.key, heap->hda[(i - 1) / 2].key) < 0) {
		heap->hda[i] = heap->hda[(i - 1) / 2];
	}
	heap->hda[i] = new_node;
}

HEAPDATA heap_find_min(HEAP *heap) {
	if (heap->size == 0) {
		HEAPDATA empty = { 0 };
		return empty;
	}
	return heap->hda[0];
}

HEAPDATA heap_extract_min(HEAP *heap) {
	if (heap->size == 0) {
		return (HEAPDATA ) { 0 } ;
			}
			HEAPDATA min = heap->hda[0];
			heap->hda[0] = heap->hda[--heap->size];
			int i = 0;

			while (1) {
				int left_child = 2 * i + 1;
				int right_child = 2 * i + 2;
				int smallest = i;

				if (left_child < heap->size
						&& cmp(heap->hda[left_child].key, heap->hda[i].key) < 0)
					smallest = left_child;
				if (right_child < heap->size
						&& cmp(heap->hda[right_child].key,
								heap->hda[smallest].key) < 0)
					smallest = right_child;

				if (smallest == i)
					break;

				HEAPDATA temp = heap->hda[i];
				heap->hda[i] = heap->hda[smallest];
				heap->hda[smallest] = temp;
				i = smallest;

			}
			return min;
		}

		int heap_change_key(HEAP *heap, int index, KEYTYPE new_key) {
			if (index < 0 || index >= heap->size)
				return -1;

			HEAPDATA node = heap->hda[index];
			node.key = new_key;

			while (index && cmp(heap->hda[(index - 1) / 2].key, node.key) > 0) {
				heap->hda[index] = heap->hda[(index - 1) / 2];
				index = (index - 1) / 2;
			}

			while (1) {
				int left_child = 2 * index + 1;
				int right_child = 2 * index + 2;
				int smallest = index;

				if (left_child < heap->size
						&& cmp(heap->hda[left_child].key, node.key) < 0)
					smallest = left_child;
				if (right_child < heap->size
						&& cmp(heap->hda[right_child].key,
								heap->hda[smallest].key) < 0)
					smallest = right_child;

				if (smallest == index)
					break;

				heap->hda[index] = heap->hda[smallest];
				index = smallest;
			}
			heap->hda[index] = node;

			return index;
		}

		int heap_search_data(HEAP *heap, VALUETYPE data) {
			for (int i = 0; i < heap->size; i++) {
				if (heap->hda[i].value == data)
					return i;
			}
			return -1;
		}

		void heap_clean(HEAP **heapp) {
			if (heapp) {
				HEAP *heap = *heapp;
				if (heap->capacity > 0) {
					heap->capacity = 0;
					heap->size = 0;
					free(heap->hda);
					free(heap);
				}
				*heapp = NULL;
			}
		}
