#include "ragged_arr.h"

raggedArr ragArr;

int fill_mode();
int output_mode();

int main() {

	int errorStatus, outputCheck;
	int mainRows, mainCols;	

	errorStatus = fill_mode();
	if (errorStatus == -1) {
		return -1;
	}

	array_screen_print();

	output_mode();
	
	memory_release();
	return 0;

}

int fill_mode(){

	int userChoice, errorStatus=0;
	const char *textFileName="src.txt", binFileName[]="src.bin";
// FILL MODE
	do {
		printf("Select the array fill mode:\nUser input(1)\nArray from text file(2)\nArray from binary file(3)\n> "); 
		scanf("%d", &userChoice);
		switch (userChoice) {
			case 1:	rows_cols_user_scan();	
					array_user_fill();
					break;
			case 2: errorStatus = array_read_txt(textFileName);	
					break;
			case 3: errorStatus = array_read_binary(binFileName);
					break;
			default: printf("Mode must satisfy (1 <= choice <= 3)\n"); 
					 errorStatus = -1;
		}
	}while((userChoice < 1)||(userChoice > 3));

	if (errorStatus == -1)
		return -1;

	return 0;
}

int output_mode(){

	int userChoice, errorStatus;

	const char *textFileName="src.txt", binFileName[]="src.bin";
// OUTPUT MODE
	do {
		printf("Select the array output mode:\nSave to text file(1)\nSave to binary file(2)\n> "); 
		scanf("%d", &userChoice);
		switch (userChoice) {
			case 1: errorStatus  = array_save_txt(textFileName);	
					break;
			case 2: errorStatus = array_save_binary(binFileName);
					break;
			default: printf("Mode must satisfy (choice = 1 or choice = 2)\n");
		}
	}while((userChoice != 1)&&(userChoice != 2));

	if (errorStatus == -1)
		return -1;

	return 0;
}
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
	for (int i = 0; i <= rows; i++)
		free(ragArr.data[i]);
	free(ragArr.data);
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
