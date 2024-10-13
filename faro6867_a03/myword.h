/*
 -------------------------------------
 File:    myword.h
 Project: faro6867_a03
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-01-30
 -------------------------------------
 */
#ifndef MYWORD_H_
#define MYWORD_H_

typedef enum boolean {
// your code
	FALSE,
	TRUE
} BOOLEAN;

typedef struct word {
//your code
	char word[20];
	int count;

} WORD;

typedef struct wordstats {
// your code
	int line_count;
	int word_count;
	int keyword_count;
} WORDSTATS;

int create_dictionary(FILE *fp, char *dictrionay);

BOOLEAN contain_word(char *dictionary, char *word);

WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary);

#endif /* MYWORD_H_ */
