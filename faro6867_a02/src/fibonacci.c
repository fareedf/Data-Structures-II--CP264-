/*
 -------------------------------------
 File:    fibonacci.c
 Project: faro6867_a02
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-01-23
 -------------------------------------
 */
#include "fibonacci.h"

int iterative_fibonacci(int n) {
	if (n <= 1) {
		return n;
	} else {
		int f1 = 1, f2 = 1, i = 2;
		while (i < n) {
			int temp = f2;
			f2 = f1 + f2;
			f1 = temp;
			i++;
		}
		return f2;
	}
}

int recursive_fibonacci(int n) {
	if (n <= 1) {
		return n;
	} else {
		return recursive_fibonacci(n - 2) + recursive_fibonacci(n - 1);
	}
}

int dpbu_fibonacci(int *f, int n) {

	if (n >= 0) {
		for (int i = 0; i <= n; i++) {
			*(f + i) = -1;
		}
		*(f + 0) = 0;
		*(f + 1) = 1;
		for (int i = 2; i <= n; i++) {
			*(f + i) = *(f + i - 2) + *(f + i - 1);
		}
	}
	return *(f + n);
}

int dptd_fibonacci(int *f, int n) {
	if (n <= 1) {
		*(f + n) = n;
		return n;
	}
	if (*(f + n) >= 0) {
		return *(f + n);
	} else {
		*(f + n) = dptd_fibonacci(f, n - 2) + dptd_fibonacci(f, n - 1);
		return *(f + n);
	}
}
