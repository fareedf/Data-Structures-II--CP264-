/*
 -------------------------------------
 File:    queue.c
 Project: faro6867_a06
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-02-27
 -------------------------------------
 */

#include <stdio.h>
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
// your code
	np->next = NULL;
	if (qp->length == 0) {
		qp->front = np;
		qp->rear = np;
	} else {
		qp->rear->next = np;
		qp->rear = np;
	}
	qp->length += 1;
}

NODE* dequeue(QUEUE *qp) {
// your code
	if (qp->front == NULL) {
		return NULL;
	}
	NODE *temp = qp->front;
	qp->front = qp->front->next;
	if (qp->length == 1) {
		qp->rear = qp->front;
	}

	qp->length -= 1;

	return temp;
}

void clean_queue(QUEUE *qp) {
	clean(&(qp->front));
	qp->front = NULL;
	qp->rear = NULL;
	qp->length = 0;
}
