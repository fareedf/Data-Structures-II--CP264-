/*
 -------------------------------------
 File:    myword.c
 Project: faro6867_a03
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-01-30
 -------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include "myword.h"

#define MAX_LINE_LEN 1000
#define MAX_WORDS 1000

// You can copy here the functions in mystring.c if you want to use them in the
// following functions. You can also add other auxiliary functions here.

/**
 *  add your comment
 */
int create_dictionary(FILE *fp, char *dictionary) {
// your code
	char line[1000];
	char delimiters[] = " .,\n\t\r";
	char *token;
	int count = 0;

	while (fgets(line, sizeof(line), fp) != NULL) {
		strlwr(line);
		token = strtok(line, delimiters);
		while (token != NULL) {
			strcat(dictionary, token);
			strcat(dictionary, ","); // Add space instead of comma
			token = strtok(NULL, delimiters);
			count++;
		}
	}

	return count;

}

/**
 *  add your comment
 */
BOOLEAN contain_word(char *dictionary, char *word) {
// your code
	if (word == NULL || *word == '\0') {
		return 0;
	} else {
		char temp[100] = { 0 };
		strcat(temp, ",");
		strcat(temp, word);
		strcat(temp, ",");
		return (strstr(dictionary, temp) != NULL);
	}
}

/**
 *  add your comment
 */
WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary) {
	// your code
	WORDSTATS ws = { 0 };
	char line[MAX_LINE_LEN];
	char delimiters[] = " .,\n\t\r";
	char *word_token;

	while (fgets(line, MAX_LINE_LEN, fp) != NULL) { // traversing all lines
		ws.line_count++;

		strlwr(line);

		word_token = strtok(line, delimiters);
		while (word_token != NULL) {
			if (!contain_word(dictionary, word_token)) {
				int j = 0;
				while (j < ws.keyword_count
						&& strcmp(word_token, words[j].word) != 0)
					j++;

				if (j < ws.keyword_count) { // Found
					words[j].count++;
				} else {
					strcpy(words[ws.keyword_count].word, word_token);
					words[ws.keyword_count].count = 1;
					ws.keyword_count++;
				}

				ws.word_count++;
			}
			word_token = strtok(NULL, delimiters);
		}
	}

	return ws;
}
