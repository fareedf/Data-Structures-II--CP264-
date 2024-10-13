/*
 -------------------------------------
 File:    factorial.c
 Project: faro6867_a01
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-01-17
 -------------------------------------
 */

#include "factorial.h"

int factorial(int n) {
	int f = 1;

	if (n >= 1) {
		for (int i = 1; i <= n; i++) {
			int overflow = f;
			f = f * i;
			if (overflow != f / i) {
				return 0;
			}
		}
	}

	return f;
}
