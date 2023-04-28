#include <stdio.h>
#include <stdlib.h>

#include "ragged_arr.h"

int get_len(int *arr) {

	int counter=0;
	while (arr[counter]!='\n')	
		counter++;
	return counter;

}

void array_init(raggedArr ragArr) {

	ragArr.data= (int**)malloc(sizeof(int*));

}

void memory_release(raggedArr ragArr) {
	for (int i = 0; i != TERMINAL_VALUE; i++)
		free(ragArr.data[i]);
	free(ragArr.data);
}

int get_rows(int &rows) {
	do {
		printf("rows = "); scanf("%d", &rows);
	}while(rows <= 0);

	return rows;
}

int fill_mode(raggedArr ragArr){

	int userChoice, errorStatus=0, rows, cols;
	char textFileName[]="src.txt", binFileName[]="src.bin";
// FILL MODE
	do {
		printf("Select the array fill mode:\nUser input(1)\nArray from text file(2)\nArray from binary file(3)\n> "); 
		scanf("%d", &userChoice);
		switch (userChoice) {
			case 1:	get_rows(rows);
					array_user_fill(ragArr.data, rows, cols);
					break;
			case 2: errorStatus = array_read_txt(ragArr.data, rows, cols, textFileName);	
					break;
			case 3: errorStatus = array_read_binary(ragArr.data, rows, cols, binFileName);
					break;
			default: printf("Mode must satisfy (1 <= choice <= 3)\n"); 
					 errorStatus = -1;
		}
	}while((userChoice < 1)||(userChoice > 3));

	if (errorStatus == -1)
		return -1;

	return 0;
}

int output_mode(raggedArr ragArr, int rows, int cols){

	int userChoice, errorStatus;

	char textFileName[]="src.txt", binFileName[]="src.bin";
// OUTPUT MODE
	do {
		printf("Select the array output mode:\nSave to text file(1)\nSave to binary file(2)\n> "); 
		scanf("%d", &userChoice);
		switch (userChoice) {
			case 1: errorStatus  = array_save_txt(ragArr.data, rows, cols, textFileName);	
					break;
			case 2: errorStatus = array_save_binary(ragArr.data, rows, cols, binFileName);
					break;
			default: printf("Mode must satisfy (choice = 1 or choice = 2)\n");
		}
	}while((userChoice != 1)&&(userChoice != 2));

	if (errorStatus == -1)
		return -1;

	return 0;
}

void array_user_fill(raggedArr ragArr, int rows) {
	for (int i = 0; i < rows; i++) {
		int cols;
		scanf("%d", &cols);
		for (int j = 0; j < cols; j++) {
			printf(": "); scanf("%d", &ragArr.data[i][j]);
		}
	}	

}

int array_read_txt(raggedArr ragArr, int &rows, int &cols, char *fileName) {
	FILE *ft;
	ft=fopen(fileName,"rt");	

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

int array_read_binary(raggedArr ragArr, int &rows, int &cols, char *fileName) {
	
	FILE *ft;
	ft=fopen(fileName,"rb");	

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

	for (int i = 0; ragArr.data[i][0] != '\n'; i++) {
		for (int j = 0; ragArr.data[i][j] != '\n'; j++) {
			printf("%c", ragArr.data[i][j]);
		}
		printf("\n");
	}
}

int array_save_txt(raggedArr ragArr, int rows, int cols, char *fileName) {

	FILE *ft;
	ft=fopen(fileName,"wt");	

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

int array_save_binary(raggedArr ragArr, int rows, int cols, char *fileName) {

	FILE *ft;
	ft=fopen(fileName,"wb");	

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
