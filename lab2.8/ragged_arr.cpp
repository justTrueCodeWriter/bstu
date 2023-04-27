#include <stdio.h>
#include <stdlib.h>

#include "ragged_arr.h"

int get_len(char *stringArr) {

	int counter=0;
	while (stringArr[counter]!='\n')	
		counter++;
	return counter;

}

void array_init(char **arr) {

	arr = (char**)malloc(sizeof(char*));

}

int fill_mode(char **arr, int &mainRows, int &mainCols){

	int userChoice, errorStatus=0, rows, cols;
	char textFileName[]="src.txt", binFileName[]="src.bin";
// FILL MODE
	do {
		printf("Select the array fill mode:\nUser input(1)\nArray from text file(2)\nArray from binary file(3)\n> "); 
		scanf("%d", &userChoice);
		switch (userChoice) {
			case 1:	array_user_fill(arr, rows, cols);
					break;
			case 2: errorStatus = array_read_txt(arr, rows, cols, textFileName);	
					break;
			case 3: errorStatus = array_read_binary(arr, rows, cols, binFileName);
					break;
			default: printf("Mode must satisfy (1 <= choice <= 3)\n"); 
					 errorStatus = -1;
		}
	}while((userChoice < 1)||(userChoice > 3));

	if (errorStatus == -1)
		return -1;

	mainRows = rows;
	mainCols = cols;

	return 0;
}

int output_mode(char **arr, int rows, int cols){

	int userChoice, errorStatus;

	char textFileName[]="src.txt", binFileName[]="src.bin";
// OUTPUT MODE
	do {
		printf("Select the array output mode:\nSave to text file(1)\nSave to binary file(2)\n> "); 
		scanf("%d", &userChoice);
		switch (userChoice) {
			case 1: errorStatus  = array_save_txt(arr, rows, cols, textFileName);	
					break;
			case 2: errorStatus = array_save_binary(arr, rows, cols, binFileName);
					break;
			default: printf("Mode must satisfy (choice = 1 or choice = 2)\n");
		}
	}while((userChoice != 1)&&(userChoice != 2));

	if (errorStatus == -1)
		return -1;

	return 0;
}

void array_user_fill(char **arr, int rows, int cols) {

	for (int i = 0; *arr[i]!='\n'; i++)
		fgets(arr[i], 1000, stdin);	
}

int array_read_txt(char **arr, int &rows, int &cols, char *fileName) {
	FILE *ft;
	ft=fopen(fileName,"rt");	

	if (ft == NULL) {
		printf("ERROR: CANT'T FIND SOURCE FILE\n");
		return -1;
	}

	fscanf(ft, "%d %d", &rows, &cols);

	for (int i = 0; i < rows; i++) {
			fgets(arr[i], 1000, ft);
	}
		
	fclose(ft);

	return 0;

}

int array_read_binary(char **arr, int &rows, int &cols, char *fileName) {
	
	FILE *ft;
	ft=fopen(fileName,"rb");	

	if (ft == NULL) {
		printf("ERROR: CANT'T FIND SOURCE FILE\n");
		return -1;
	}

	fread(&rows, sizeof(int), 1, ft);
	fread(&cols, sizeof(int), 1, ft);

	for (int i = 0; i < rows; i++) {
			fread(&arr[i][0], sizeof(double), cols, ft);
	}
		
	fclose(ft);

	return 0;

}

void array_screen_print(char **arr, int rows, int cols) {

	for (int i = 0; i < rows; i++) {
			printf("%s\n", arr[i]);
	}
}

int array_save_txt(char **arr, int rows, int cols, char *fileName) {

	FILE *ft;
	ft=fopen(fileName,"wt");	

	if (ft == NULL) {
		printf("ERROR: CANT'T FIND SOURCE FILE\n");
		return -1;
	}

	fprintf(ft, "%d %d\n", rows, cols);

	for (int i = 0; i < rows; i++) {
			fprintf(ft, "%s\n", arr[i]);
	}
		
	fclose(ft);

	return 0;
}

int array_save_binary(char **arr, int rows, int cols, char *fileName) {

	FILE *ft;
	ft=fopen(fileName,"wb");	

	if (ft == NULL) {
		printf("ERROR: CANT'T FIND SOURCE FILE\n");
		return -1;
	}

	fwrite(&rows, sizeof(int), 1, ft);
	fwrite(&cols, sizeof(int), 1, ft);

	for (int i = 0; i < rows; i++) {
			fwrite(&arr[i][0], sizeof(double), cols, ft);
	}
		
	fclose(ft);

	return 0;
}
