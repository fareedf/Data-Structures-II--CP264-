/*
 -------------------------------------
 File:    mysort.c
 Project: faro6867_l05
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-02-10
 -------------------------------------
 */

#include "mysort.h"

void select_sort_inc(float *a[], int left, int right) {
// your code
	int i, j, k;
	float *temp;
	for (i = left; i <= right; i++) {
		k = i;
		for (j = i + 1; j <= right; j++) {
			if (*a[j] < *a[k]) {
				k = j;
			}
		}
		if (k != i) {
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
	}
}

void quick_sort_inc(float *a[], int left, int right) {
// your code
	if (left < right) {
		float key = *(a[left]);
		int i = left + 1;
		int j = right;

		while (i <= j) {
			while (i <= right && *(a[i]) <= key)
				i++;

			while (j >= left && *(a[j]) > key)
				j--;

			if (i < j) {
				float *temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}

		float *temp = a[left];
		a[left] = a[j];
		a[j] = temp;

		quick_sort_inc(a, left, j - 1);
		quick_sort_inc(a, j + 1, right);
	}
}
