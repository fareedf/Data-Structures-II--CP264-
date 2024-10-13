/*
 -------------------------------------
 File:    expression_symbol.h
 Project: faro6867_a09
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-03-23
 -------------------------------------
 */
#ifndef EXPRESSION_SYMBOL_H_
#define EXPRESSION_SYMBOL_H_

#include "common_queue_stack.h"
#include "hash.h"

QUEUE infix_to_postfix_symbol(HASHTABLE *ht, char *infixstr);

int evaluate_infix_symbol(HASHTABLE *ht, char *infixstr);

int evaluate_postfix(QUEUE queue);

HASHDATA evaluate_statement(HASHTABLE *ht, char *statement);

#endif /* EXPRESSION_SYMBOL_H_ */
