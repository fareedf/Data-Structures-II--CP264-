/*
 -------------------------------------
 File:    bigint.h
 Project: faro6867_a05
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-02-17
 -------------------------------------
 */
#ifndef BIGINT_H_
#define BIGINT_H_
#include "dllist.h"

/*
 * Define BIGINT as DLL
 */
typedef DLL BIGINT;

/*
 * Creates and returns BIGINT object by converting the digit string.
 */
BIGINT bigint(char *digitstr);

/*
 * Add two BIGINT operants and returns the sum in BIGINT type.
 * @param oprand1  - first operand of BIGINT type.
 * @param oprand2  - second operand of BIGINT type.
 * @return - the sum of oprand1 and oprand2 in BIGINT type.
 */
BIGINT bigint_add(BIGINT oprand1, BIGINT oprand2);

/*
 * Compute and return Fibonacci(n)
 * @param n - input positive integer
 * @return  - Fibonacci(n) in BIGINT type
 */
BIGINT bigint_fibonacci(int n);

#endif /* BIGINT_H_ */
