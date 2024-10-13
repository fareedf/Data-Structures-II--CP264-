/*
 -------------------------------------
 File:    mychar.c
 Project: faro6867_a01
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-01-17
 -------------------------------------
 */

#include "mychar.h"

int mytype(char c) {
	if (c >= '0' && c <= '9') {
		return 0;
	} else if (c == '+' || c == '-' || c == '/' || c == '*' || c == '%') {
		return 1;
	} else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
		return 2;
	} else {
		return -1;
	}
}

char case_flip(char c) {
	if (c >= 'a' && c <= 'z') {
		return c - ('a' - 'A');
	} else if (c >= 'A' && c <= 'Z') {
		return c + ('a' - 'A');
	} else {
		return c;
	}
}

int char_to_int(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	} else {
		return -1;
	}
}
