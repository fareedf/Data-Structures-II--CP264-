/*
 -------------------------------------
 File:    expression.c
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
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"

QUEUE infix_to_postfix(char *infixstr) {
// your code
	char *p = infixstr;
	QUEUE queue = { 0 };
	STACK stack = { 0 };
	int sign = 1, num = 0;

	while (*p) {
		if (*p == '-' && (p == infixstr || *(p - 1) == '(')) {
			sign = -1;
		} else if (get_type(*p) == 0) {
			num = *p - '0';
			while (*(p + 1) >= '0' && *(p + 1) <= '9') {
				num = num * 10 + *(p + 1) - '0';
				p++;
			}
			enqueue(&queue, new_node(sign * num, 0));
			sign = 1;
		} else if (get_type(*p) == 1) {
			while (stack.top
					&& get_priority(*p) <= get_priority(stack.top->data)) {
				enqueue(&queue, pop(&stack));
			}
			push(&stack, new_node(*p, 1));
		} else if (get_type(*p) == 2) { // '('
			push(&stack, new_node(*p, 2));
		} else if (get_type(*p) == 3) { // ')'
			while (stack.top && stack.top->data != '(') {
				enqueue(&queue, pop(&stack));
			}
			pop(&stack);
		}
		p++;
	}

	while (stack.top) {
		enqueue(&queue, pop(&stack));
	}
	return queue;
}

int evaluate_postfix(QUEUE queue) {
// your code
	NODE *p = queue.front;
	STACK stack = { 0 };
	int type = 0;

	while (p) {
		type = p->type;
		if (type == 0) {
			push(&stack, new_node(p->data, 0));
		} else if (type == 1) {
			int operand2 = stack.top->data;
			pop(&stack);
			int operand1 = stack.top->data;
			pop(&stack);

			if (p->data == '+') {
				push(&stack, new_node(operand1 + operand2, 0));
			} else if (p->data == '-') {
				push(&stack, new_node(operand1 - operand2, 0));
			} else if (p->data == '*') {
				push(&stack, new_node(operand1 * operand2, 0));
			} else if (p->data == '/') {
				push(&stack, new_node(operand1 / operand2, 0));
			}
		}
		p = p->next;
	}

	int result = stack.top->data;
	clean_stack(&stack);
	return result;
}

int evaluate_infix(char *infixstr) {
// your code
	QUEUE postfix_queue = infix_to_postfix(infixstr);

	int result = evaluate_postfix(postfix_queue);

	clean(&postfix_queue.front);
	return result;
}
