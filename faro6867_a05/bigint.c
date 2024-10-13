/*
 -------------------------------------
 File:    bigint.c
 Project: faro6867_a05
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-02-17
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

BIGINT bigint(char *p) {
	BIGINT bn = { 0 };
	if (p == NULL)
		return bn;
	else if (!(*p >= '0' && *p <= '9')) { // not begin with digits
		return bn;
	} else if (*p == '0' && *(p + 1) == '\0') { // just "0"
		dll_insert_end(&bn, new_node(*p - '0'));
		return bn;
	} else {
		while (*p) {
			if (*p >= '0' && *p <= '9') {
				dll_insert_end(&bn, new_node(*p - '0'));
			} else {
				dll_clean(&bn);
				break;
			}
			p++;
		}
		return bn;
	}
}

BIGINT bigint_add(BIGINT op1, BIGINT op2) {
	BIGINT sum = bigint(NULL);
	NODE *p1 = op1.end;
	NODE *p2 = op2.end;
	int c = 0, a, b, s;
	while (p1 || p2) {
		a = 0;
		b = 0;
		if (p1) {
			a = p1->data;
			p1 = p1->prev;
		}
		if (p2) {
			b = p2->data;
			p2 = p2->prev;
		}
		s = a + b + c;
		if (s >= 10) {
			dll_insert_start(&sum, new_node(s - 10));
			c = 1;
		} else {
			dll_insert_start(&sum, new_node(s));
			c = 0;
		}
	}
	if (c == 1)
		dll_insert_start(&sum, new_node(1));
	return sum;
}

BIGINT bigint_fibonacci(int n) {
	BIGINT f1 = bigint("0");
	BIGINT f2 = bigint("1");
	BIGINT temp = bigint(NULL);
	if (n == 0)
		return f1;
	else if (n == 1)
		return f2;
	else {
		for (int i = 2; i <= n; i++) {
			temp = bigint_add(f1, f2);
			dll_clean(&f1);
			f1 = f2;
			f2 = temp;
		}
		return f2;
	}
}
