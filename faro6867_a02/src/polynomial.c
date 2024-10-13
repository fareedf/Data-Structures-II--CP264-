/*
 -------------------------------------
 File:    polynomial.c
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
#include "polynomial.h"

#define EPSILON 1e-6

float horner(float *p, int n, float x) {
// your code
	float r = 0;
	for (int i = 0; i < n; i++) {
		r = r * x + *(p + i);
	}
	return r;
}

float bisection(float *p, int n, float a, float b) {
	float pc, pa;
	while (1) {
		float c = (a + b) / 2;
		pc = horner(p, n, c);
		pa = horner(p, n, a);
		if (fabs(pc) < EPSILON || fabs(a - b) < EPSILON) {
			return c;
		} else if (pc * pa > 0) {
			a = c;
		} else {
			b = c;
		}
	}

}
