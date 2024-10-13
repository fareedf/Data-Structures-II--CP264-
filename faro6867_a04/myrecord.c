/*
 -------------------------------------
 File:    myrecord.c
 Project: faro6867_l05
 file description
 -------------------------------------
 Author:  Fareed Farooq
 ID:      169026867
 Email:   faro6867@mylaurier.ca
 Version  2024-02-10
 -------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"
#include "mysort.h"

GRADE grade(float score) {
	GRADE r = { "F" };
	char g[14][3] = { "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+",
			"D", "D-", "F" };
	int b[] = { 100, 90, 85, 80, 77, 73, 70, 67, 63, 60, 57, 53, 50, 0 };
	int i;
	int n = sizeof(b) / sizeof(int);

	for (i = 0; i < n; i++) {
		if (score >= b[i + 1])
			break;
	}
	strcpy(r.letter_grade, g[i]);

	return r;
}

STATS process_data(RECORD *dataset, int count) {
	STATS stats = { 0 };
	float sum = 0;
	for (int i = 0; i < count; i++) {
		sum += dataset[i].score;
	}
	stats.mean = sum / count;

	float sum_of_squares = 0;
	for (int i = 0; i < count; i++) {
		sum_of_squares += pow(dataset[i].score - stats.mean, 2);
	}
	stats.stddev = sqrt(sum_of_squares / count);

	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (dataset[j].score > dataset[j + 1].score) {
				RECORD temp = dataset[j];
				dataset[j] = dataset[j + 1];
				dataset[j + 1] = temp;
			}
		}
	}
	if (count % 2 == 0) {
		stats.median = (dataset[count / 2 - 1].score + dataset[count / 2].score)
				/ 2.0;
	} else {
		stats.median = dataset[count / 2].score;
	}
	stats.count = count;
	return stats;
}

int import_data(FILE *fp, RECORD *dataset) {
	char delimiters[] = ",\n\r";
	char line[100];
	int i = 0;
	char *token = NULL;
	while (fgets(line, sizeof(line), fp) != NULL) {
		token = strtok(line, delimiters);
		strcpy(dataset[i].name, token);
		token = strtok(NULL, delimiters);
		sscanf(token, "%f", &dataset[i].score);
		i++;
	}
	return i;
}

int report_data(FILE *fp, RECORD *dataset, int count) {
	int i;
	for (i = 0; i < count; i++) {
		fprintf(fp, "%s,%.1f,%s\n", dataset[i].name, dataset[i].score,
				grade(dataset[i].score).letter_grade);
	}
	return 1;
}
