/*
 -------------------------------------
 File:    heap.h
 Project: faro6867_a09
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-03-23
 -------------------------------------
 */
#ifndef HEAP_H_
#define HEAP_H_

typedef int KEYTYPE;
typedef int VALUETYPE;

typedef struct {
	KEYTYPE key;
	VALUETYPE value;
} HEAPDATA;

typedef struct heap {
	unsigned int size;
	unsigned int capacity;
	HEAPDATA *hda;
} HEAP;

HEAP* new_heap(int capacity);

void heap_insert(HEAP *heap, HEAPDATA data);

HEAPDATA heap_find_min(HEAP *heap);

HEAPDATA heap_extract_min(HEAP *heap);

int heap_change_key(HEAP *heap, int index, KEYTYPE new_key);

int heap_search_data(HEAP *heap, VALUETYPE val);

void heap_clean(HEAP **heapp);

#endif /* HEAP_H_ */
