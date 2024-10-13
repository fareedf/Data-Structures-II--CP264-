/*
 -------------------------------------
 File:    matrix.c
 Project: faro6867_a02
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-01-25
 -------------------------------------
 */

#include <stdio.h>
#include <math.h>
#include "matrix.h"

float norm(float *v, int n) {
// your code
	float square = 0;
	for (int i = 0; i < n; i++) {
		square += pow(*(v + i), 2);
	}
	float norm = sqrt(square);
	return norm;
}

float dot_product(float *v1, float *v2, int n) {
// your code
	float dot = 0;
	for (int i = 0; i < n; i++) {
		dot += *(v1 + i) * *(v2 + i);
	}
	return dot;
}

void matrix_multiply_vector(float *m, float *v, float *vout, int n) {
// your code
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum += *(m + i * n + j) * *(v + j);
		}
		*(vout + i) = sum;
	}
}

void matrix_multiply_matrix(float *m1, float *m2, float *m3, int n) {
// your code
	float s = 0;
	int i, j, k;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			s = 0;
			for (k = 0; k < n; k++) {
				s += *(m1 + i * n + k) * *(m2 + k * n + j);
			}
			*(m3 + i * n + j) = s;
		}
	}
}
