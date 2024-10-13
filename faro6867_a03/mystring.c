/*
 -------------------------------------
 File:    mystring.c
 Project: faro6867_a03
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-01-30
 -------------------------------------
 */

#include "mystring.h"
#include <stdio.h>>

/**
 * Count the number words of given simple string. A word starts with an English charactor end with a charactor of space, tab, comma, or period.
 *
 * @param s - char pointer to a str
 * @return - return the number of words.
 */
int str_words(char *s) {

	if (s == NULL) {
		return -1;
	}

	int word = 0;
	char *p = s;

	while (*p) {
		if ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) {
			word += 1;
			while (*p && (*p != ' ' && *p != '\t' && *p != ',' && *p != '.')) {
				p++;
			}
		} else {
			p++;
		}
	}
	return word;
}

/**
 * Change every upper case English letter to its lower case of string passed by s
 *
 * @param s - char pointer to a str
 * @return - return the number of actual flips.
 */
int str_lower(char *s) {
	if (s == NULL)
		return -1;

	int flip = 0;
	char *p = s;

	while (*p) {
		if (*p >= 'A' && *p <= 'Z') {
			*p += 32;
			flip++;
		}
		p++;
	}
	return flip;
}

/**
 * Remove unnecessary space characters in a simple string passed by `s`
 *
 * @param s - char pointer to a str
 */
void str_trim(char *s) {

	char *p = s, *dp = s;
	while (*p) {
		if (*p != ' ' || (p > s && *(p - 1) != ' ')) {
			*dp = *p;
			dp++;
		}
		p++;
	}

	while (dp > s && *(dp - 1) == ' ') {
		dp--;
	}

	*dp = '\0';
}
