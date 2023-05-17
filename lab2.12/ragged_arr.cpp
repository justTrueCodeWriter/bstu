#include <stdio.h>
#include <stdlib.h>

#include "ragged_arr.h"

raggedArr ragArr;
raggedArrSorted ragArrSort;

int get_rows_len() {

	int counter=0;
	while (ragArr.data[counter][0]!=TERMINAL_VALUE)	
		counter++;
	return counter;

}

int get_cols_len(int row) {
	int counter=0;
	while (ragArr.data[row][counter]!=TERMINAL_VALUE)	
		counter++;
	return counter;
}

void rows_cols_user_scan() {

	int rows, cols;

	int colsCountArr[rows];

	do{
		printf("rows = "); scanf("%d", &rows);
	}while(rows<=0);

	for (int i = 0; i < rows; i++) {
			do {
				printf("cols[%d] = ", i+1); scanf("%d", &cols);
			}while(cols<=0);
			colsCountArr[i] = cols;
	}

	array_init(rows, colsCountArr);
}

void array_init(int rows, int *colsCountArr) {

	ragArr.data = (int**)malloc(sizeof(int*)*(rows+1));

	for(int i = 0; i < rows; i++)	{
		ragArr.data[i] = (int*)malloc(sizeof(int)*(colsCountArr[i]+1));
		for (int j = 0; j < colsCountArr[i]; j++) {
			ragArr.data[i][j] = 0;
		}
		ragArr.data[i][colsCountArr[i]] = TERMINAL_VALUE;
	}
	ragArr.data[rows] = (int*)malloc(sizeof(int));
	*ragArr.data[rows] = TERMINAL_VALUE;

}

void memory_release() {
	int rows = get_rows_len();
	for (int i = 0; i <= rows; i++) {
		free(ragArr.data[i]);
	}
	free(ragArr.data);
}

void sort_arr_mem_release() {

	free(ragArrSort.data);

}

void array_user_fill() {
	int rows;
	rows = get_rows_len();
	for (int i = 0; i < rows; i++) {
		int cols;
		cols = get_cols_len(i);	
		printf("arr[%d] = ", i+1);
		for (int j = 0; j < cols; j++) {
			 scanf("%d", &ragArr.data[i][j]);
		}
	}

}

void array_screen_print() {

	for (int i = 0; ragArr.data[i][0] != TERMINAL_VALUE; i++) {
		for (int j = 0; ragArr.data[i][j] != TERMINAL_VALUE; j++) {
			printf("%d ", ragArr.data[i][j]);
		}
		printf("\n");
	}

}

int array_read_txt(const char *fileName) {
	FILE *ft;
	ft=fopen(fileName,"rt");	

	int rows, cols;

	if (ft == NULL) {
		printf("ERROR: CANT'T FIND SOURCE FILE\n");
		return -1;
	}

	fscanf(ft, "%d", &rows);
	int colsCountArr[rows];

	for (int i = 0; i < rows; i++) {
			fscanf(ft, "%d", &colsCountArr[i]);
	}

	array_init(rows, colsCountArr);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colsCountArr[i]; j++) {
				fscanf(ft, "%d", &ragArr.data[i][j]);
		}
	}
		
	fclose(ft);

	return 0;

}

int array_read_binary(const char *fileName) {
	
	FILE *ft;
	ft=fopen(fileName,"rb");	

	int rows, cols;
	if (ft == NULL) {
		printf("ERROR: CANT'T FIND SOURCE FILE\n");
		return -1;
	}

	fread(&rows, sizeof(int), 1, ft);
	int colsCountArr[rows];

	for (int i = 0; i < rows; i++) {
			fread(&colsCountArr[i], sizeof(int), 1, ft);
	}

	array_init(rows, colsCountArr);

	for (int i = 0; i < rows; i++) {
			fread(&ragArr.data[i][0], sizeof(int), colsCountArr[i], ft);
	}
		
	fclose(ft);

	return 0;

}

int array_save_txt(const char *fileName) {

	FILE *ft;
	ft=fopen(fileName,"wt");	

	int rows, cols;

	if (ft == NULL) {
		printf("ERROR: CANT'T FIND SOURCE FILE\n");
		return -1;
	}


	rows = get_rows_len();
	int colsCountArr[rows];

	fprintf(ft, "%d\n", rows);
	for (int i = 0; i < rows; i++) {
			cols = get_cols_len(i);
			colsCountArr[i] = cols;
			fprintf(ft, "%d ", cols);
	}
	fprintf(ft, "\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colsCountArr[i]; j++) {
				fprintf(ft, "%d ", ragArr.data[i][j]);
		}
		fprintf(ft, "\n");
	}	
	fclose(ft);

	return 0;
}

int array_save_binary(const char *fileName) {

	FILE *ft;
	ft=fopen(fileName,"wb");	

	int rows, cols;

	if (ft == NULL) {
		printf("ERROR: CANT'T FIND SOURCE FILE\n");
		return -1;
	}

	rows = get_rows_len();	

	int colsCountArr[rows];

	fwrite(&rows, sizeof(int), 1, ft);
	for (int i = 0; i < rows; i++) {
			cols = get_cols_len(i);
			colsCountArr[i] = cols;
			fwrite(&cols, sizeof(int), 1, ft);
	}

	for (int i = 0; i < rows; i++) {
			fwrite(&ragArr.data[i][0], sizeof(int), colsCountArr[i], ft);
	}
		
	fclose(ft);

	return 0;
}

void add_last_line() {
	
	int rows, cols;

	rows = get_rows_len();	

	printf("cols = "); scanf("%d", &cols);

	ragArr.data = (int**)realloc(ragArr.data, sizeof(int*)*(rows+2));

	free(ragArr.data[rows]);

	ragArr.data[rows] = (int*)malloc(sizeof(int)*(cols+1));
	for (int i = 0; i < cols; i++)
		scanf("%d", &ragArr.data[rows][i]);

	ragArr.data[rows][cols] = TERMINAL_VALUE;

	ragArr.data[rows+1] = (int*)malloc(sizeof(int));
	*ragArr.data[rows+1] = TERMINAL_VALUE;
}

void delete_last_line() {

	int rows = get_rows_len();

	*ragArr.data[rows-1] = TERMINAL_VALUE;

	free(ragArr.data[rows]);

	ragArr.data = (int**)realloc(ragArr.data, sizeof(int*)*(rows));

}

void sort_by_length() {

	int rows = get_rows_len();

	for (int i = 0; i<rows-1; i++) {
		for (int j = 0; j < rows-i-1; j++)	{
			if (get_cols_len(j)>get_cols_len(j+1)) {
				int *tmp = ragArr.data[j];
				ragArr.data[j] = ragArr.data[j+1];
				ragArr.data[j+1] = tmp;
			}
		}
		
	}	

}

//TODO: сортировка строк по длине
