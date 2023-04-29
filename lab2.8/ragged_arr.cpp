#include <stdio.h>
#include <stdlib.h>

#include "ragged_arr.h"

raggedArr ragArr;







// TODO: rewrite from single to multi







int get_rows_len(raggedArr ragArr) {

	int counter=0;
	while (ragArr.data[counter][0]!=TERMINAL_VALUE)	
		counter++;
	return counter;

}

int get_cols_len(raggedArr ragArr, int row) {
	int counter=0;
	while (ragArr.data[row][counter]!=TERMINAL_VALUE)	
		counter++;
	return counter;
}

void array_init(raggedArr ragArr) {

	int rows, cols;

	do{
		printf("rows = "); scanf("%d", &rows);
	}while(rows<=0);

	ragArr.data = (int**)malloc(sizeof(int*)*(rows+1));

	for(int i = 0; i < rows; i++)	{
		do {
			printf("cols[%d] = ", i+1); scanf("%d", &cols);
		}while(cols<=0);
		ragArr.data[i] = (int*)malloc(sizeof(int)*(cols+1));
		for (int j = 0; j < cols; j++) {
			ragArr.data[i][j] = 0;
		}
		ragArr.data[i][cols] = TERMINAL_VALUE;
	}
	ragArr.data[rows] = (int*)malloc(sizeof(int));
	*ragArr.data[rows] = TERMINAL_VALUE;

	ragArr.data[0][1] = 5;
	printf("%d\n", ragArr.data[0][1]);

}

void memory_release(raggedArr ragArr) {
	for (int i = 0; i != TERMINAL_VALUE; i++)
		free(ragArr.data[i]);
	free(ragArr.data);
}



void array_user_fill(raggedArr ragArr) {
	/*int rows;
	rows = get_rows_len(ragArr);
	for (int i = 0; i < rows; i++) {
		int cols;
		cols = get_cols_len(ragArr, i);	
		printf("arr[%d] = ", i+1);
		for (int j = 0; j < cols; j++) {
			 scanf("%d", &ragArr.data[i][j]);
		}
	}*/
	printf("%d\n", ragArr.data[0][1]);

}

int array_read_txt(raggedArr ragArr, const char *fileName) {
	FILE *ft;
	ft=fopen(fileName,"rt");	

	int rows, cols;

	if (ft == NULL) {
		printf("ERROR: CANT'T FIND SOURCE FILE\n");
		return -1;
	}

	fscanf(ft, "%d %d", &rows, &cols);

	for (int i = 0; i < rows; i++) {
	}
		
	fclose(ft);

	return 0;

}

int array_read_binary(raggedArr ragArr, const char *fileName) {
	
	FILE *ft;
	ft=fopen(fileName,"rb");	

	int rows, cols;

	if (ft == NULL) {
		printf("ERROR: CANT'T FIND SOURCE FILE\n");
		return -1;
	}

	fread(&rows, sizeof(int), 1, ft);
	fread(&cols, sizeof(int), 1, ft);

	for (int i = 0; i < rows; i++) {
			fread(&ragArr.data[i][0], sizeof(int), cols, ft);
	}
		
	fclose(ft);

	return 0;

}

void array_screen_print(raggedArr ragArr) {

	for (int i = 0; ragArr.data[i][0] != TERMINAL_VALUE; i++) {
		for (int j = 0; ragArr.data[i][j] != TERMINAL_VALUE; j++) {
			printf("%c", ragArr.data[i][j]);
		}
		printf("\n");
	}
}

int array_save_txt(raggedArr ragArr, const char *fileName) {

	FILE *ft;
	ft=fopen(fileName,"wt");	

	int rows, cols;

	if (ft == NULL) {
		printf("ERROR: CANT'T FIND SOURCE FILE\n");
		return -1;
	}

	fprintf(ft, "%d %d\n", rows, cols);

	for (int i = 0; i < rows; i++) {
			fprintf(ft, "%d\n", *ragArr.data[i]);
	}
		
	fclose(ft);

	return 0;
}

int array_save_binary(raggedArr ragArr, const char *fileName) {

	FILE *ft;
	ft=fopen(fileName,"wb");	

	int rows, cols;

	if (ft == NULL) {
		printf("ERROR: CANT'T FIND SOURCE FILE\n");
		return -1;
	}

	fwrite(&rows, sizeof(int), 1, ft);
	fwrite(&cols, sizeof(int), 1, ft);

	for (int i = 0; i < rows; i++) {
			fwrite(&ragArr.data[i][0], sizeof(int), cols, ft);
	}
		
	fclose(ft);

	return 0;
}
