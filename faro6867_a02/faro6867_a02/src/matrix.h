/*
 -------------------------------------
 File:    matrix.h
 Project: faro6867_a02
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-01-25
 -------------------------------------
 */
#ifndef MATRIX_H_
#define MATRIX_H_

float norm(float *v, int n);
float dot_product(float *v1, float *v2, int n);
void matrix_multiply_vector(float *m, float *v1, float *v2, int n);
void matrix_multiply_matrix(float *m1, float *m2, float *m3, int n);

#endif /* MATRIX_H_ */
