#include <stdio.h>
#include <stdlib.h>
#define ROWS 100
#define COLS 100

void rows_cols_scan(int &rows, int &cols);

int fill_mode(int arr[ROWS][COLS], int rows, int cols);
int output_mode(int arr[ROWS][COLS], int rows, int cols);

void user_array_filler(int arr[ROWS][COLS], int rows, int cols); 
int array_reader_txt(int arr[ROWS][COLS], char *fileName);
int array_reader_binary(int arr[ROWS][COLS], char *fileName);
void random_array_filler(int arr[ROWS][COLS], int rows, int cols);
double formula(int i, int j);
void formula_array_filler(int arr[ROWS][COLS], int rows, int cols);

void screen_array_printer(int arr[ROWS][COLS], int rows, int cols);
int array_saver_txt(int arr[ROWS][COLS], int rows, int cols, char *fileName);
int array_saver_binary(int arr[ROWS][COLS], int rows, int cols, char *fileName);

int main() {

	int arr[ROWS][COLS];
	int errorStatus, outputCheck;
	int rows, cols;	

	rows_cols_scan(rows, cols);

	errorStatus = fill_mode(arr, rows, cols);

	screen_array_printer(arr, rows, cols);

	output_mode(arr, rows, cols);
	
	return 0;

}

void rows_cols_scan(int &rows, int &cols) {

	do {
		printf("rows"); scanf("%d", &rows);		
		printf("cols"); scanf("%d", &cols);		
		if ((rows<1)||(cols<1))
			printf("INCORRECT: rows and cols must satisfy (rows > 0 and cols > 0)");
	}while((rows<1)||(cols<1));

}

int fill_mode(int arr[ROWS][COLS], int rows, int cols){

	int userChoice, errorStatus=0;
	char textFileName[]="src.txt", binFileName[]="src.bin";
// FILL MODE
	do {
		printf("Select the array fill mode:\nUser input(1)\nArray from text file(2)\nArray from binary file(3)\nRandom fill(4)\nFormula fill(5)\n> "); 
		scanf("%d", &userChoice);
		switch (userChoice) {
			case 1: user_array_filler(arr, rows, cols);
					break;
			case 2: errorStatus = array_reader_txt(arr, textFileName);	
					break;
			case 3: errorStatus = array_reader_binary(arr, binFileName);
					break;
			case 4: random_array_filler(arr, rows, cols);
					break;
			case 5: formula_array_filler(arr, rows, cols); 
					break;
			default: printf("Mode must satisfy (1 <= choice <= 5)\n");
		}
	}while((userChoice < 1)&&(userChoice > 5));

	if (errorStatus == -1)
		return -1;

	return 0;
}
int output_mode(int arr[ROWS][COLS], int rows, int cols){

	int userChoice, errorStatus;

	char textFileName[]="src.txt", binFileName[]="src.bin";
// OUTPUT MODE
	do {
		printf("Select the array output mode:\nPrint on screen(1)\nSave to text file(2)\nSave to binary file(3)\n> "); 
		scanf("%d", &userChoice);
		switch (userChoice) {
			case 1: errorStatus  = array_saver_txt(arr, rows, cols, textFileName);	
					break;
			case 2: errorStatus = array_saver_binary(arr, rows, cols, binFileName);
					break;
			default: printf("Mode must satisfy (choice = 1 or choice = 2)\n");
		}
	}while((userChoice != 1)&&(userChoice != 2));

	if (errorStatus == -1)
		return -1;

	return 0;
}

// FILLING BY USER
void user_array_filler(int arr[ROWS][COLS], int rows, int cols) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf(""); scanf("%d", &arr[i][j]);
		}
	}

}

int array_reader_txt(int arr[ROWS][COLS], char *fileName) {

	printf("array_reader_txt");
	return 0;

}

int array_reader_binary(int arr[ROWS][COLS], char *fileName) {


	printf("array_reader_binary");
	return 0;
}

void random_array_filler(int arr[ROWS][COLS], int rows, int cols) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = rand() % 999 + 1;
		}
	}

}

double formula(int i, int j) {

	if (i < j) {
		return 1.0/(i+j);
	}
	else if (i == j) {
	 return i;	
	}
	else 
		return -8.0/(i+j-1);

}

void formula_array_filler(int arr[ROWS][COLS], int rows, int cols) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = formula(i, j);
		}
	}

}

void screen_array_printer(int arr[ROWS][COLS], int rows, int cols) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int array_saver_txt(int arr[ROWS][COLS], int rows, int cols, char *fileName) {

	FILE *ft;
	ft=fopen(fileName,"wt");	

	if (ft == 0) {
		printf("ERROR: CANT'T FIND SOURCE FILE\n");
		return 0;
	}

	fprintf(ft, "%d %d", rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			fprintf(ft, "%d", arr[i][j]);
		}
		fprintf(ft, "%d", arr[i][j]);
	}
		
	fclose(ft);

	printf("array_saver_txt");
}
int array_saver_binary(int arr[ROWS][COLS], int rows, int cols, char *fileName) {


	printf("array_saver_binary");
	return 0;
}
