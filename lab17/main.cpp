#include <stdio.h>
#include <stdlib.h>
#define ROWS 100
#define COLS 100

void rows_cols_scan(int &rows, int &cols);

int fill_mode(double arr[ROWS][COLS], int &mainRows, int &mainCols);
int output_mode(double arr[ROWS][COLS], int rows, int cols);

void user_array_filler(double arr[ROWS][COLS], int rows, int cols); 
int array_reader_txt(double arr[ROWS][COLS], int &rows, int &cols, char *fileName);
int array_reader_binary(double arr[ROWS][COLS], int &rows, int &cols, char *fileName);
void random_array_filler(double arr[ROWS][COLS], int rows, int cols);
double formula(int i, int j);
void formula_array_filler(double arr[ROWS][COLS], int rows, int cols);

void screen_array_printer(double arr[ROWS][COLS], int rows, int cols);
int array_saver_txt(double arr[ROWS][COLS], int rows, int cols, char *fileName);
int array_saver_binary(double arr[ROWS][COLS], int rows, int cols, char *fileName);

int main() {

	double arr[ROWS][COLS];
	int errorStatus, outputCheck;
	int mainRows, mainCols;	


	errorStatus = fill_mode(arr, mainRows, mainCols);
	if (errorStatus == -1) {
		return -1;
	}

	screen_array_printer(arr, mainRows, mainCols);

	output_mode(arr, mainRows, mainCols);
	
	return 0;

}

void rows_cols_scan(int &rows, int &cols) {

	do {
		printf("rows "); scanf("%d", &rows);		
		printf("cols "); scanf("%d", &cols);		
		if ((rows<1)||(cols<1))
			printf("INCORRECT: rows and cols must satisfy (rows > 0 and cols > 0)");
	}while((rows<1)||(cols<1));

}

int fill_mode(double arr[ROWS][COLS], int &mainRows, int &mainCols){

	int userChoice, errorStatus=0, rows, cols;
	char textFileName[]="src.txt", binFileName[]="src.bin";
// FILL MODE
	do {
		printf("Select the array fill mode:\nUser input(1)\nArray from text file(2)\nArray from binary file(3)\nRandom fill(4)\nFormula fill(5)\n> "); 
		scanf("%d", &userChoice);
		switch (userChoice) {
			case 1: rows_cols_scan(rows, cols);
					user_array_filler(arr, rows, cols);
					break;
			case 2: errorStatus = array_reader_txt(arr, rows, cols, textFileName);	
					break;
			case 3: errorStatus = array_reader_binary(arr, rows, cols, binFileName);
					break;
			case 4: rows_cols_scan(rows, cols);
					random_array_filler(arr, rows, cols);
					break;
			case 5: rows_cols_scan(rows, cols);
					formula_array_filler(arr, rows, cols); 
					break;
			default: printf("Mode must satisfy (1 <= choice <= 5)\n"); 
					 errorStatus = -1;
		}
	}while((userChoice < 1)||(userChoice > 5));

	if (errorStatus == -1)
		return -1;

	mainRows = rows;
	mainCols = cols;

	return 0;
}
int output_mode(double arr[ROWS][COLS], int rows, int cols){

	int userChoice, errorStatus;

	char textFileName[]="src.txt", binFileName[]="src.bin";
// OUTPUT MODE
	do {
		printf("Select the array output mode:\nSave to text file(1)\nSave to binary file(2)\n> "); 
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
void user_array_filler(double arr[ROWS][COLS], int rows, int cols) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf(": "); scanf("%lf", &arr[i][j]);
		}
	}

}

int array_reader_txt(double arr[ROWS][COLS], int &rows, int &cols, char *fileName) {
	FILE *ft;
	ft=fopen(fileName,"rt");	

	if (ft == NULL) {
		printf("ERROR: CANT'T FIND SOURCE FILE\n");
		return -1;
	}

	fscanf(ft, "%d %d", &rows, &cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			fscanf(ft, "%lf", &arr[i][j]);
		}
	}
		
	fclose(ft);

	return 0;

}

int array_reader_binary(double arr[ROWS][COLS], int &rows, int &cols, char *fileName) {
	
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

void random_array_filler(double arr[ROWS][COLS], int rows, int cols) {

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

void formula_array_filler(double arr[ROWS][COLS], int rows, int cols) {

	for (int i = 1; i < rows; i++) {
		for (int j = 1; j < cols; j++) {
			arr[i][j] = formula(i, j);
		}
	}

}

void screen_array_printer(double arr[ROWS][COLS], int rows, int cols) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%lf ", arr[i][j]);
		}
		printf("\n");
	}
}

int array_saver_txt(double arr[ROWS][COLS], int rows, int cols, char *fileName) {

	FILE *ft;
	ft=fopen(fileName,"wt");	

	if (ft == NULL) {
		printf("ERROR: CANT'T FIND SOURCE FILE\n");
		return -1;
	}

	fprintf(ft, "%d %d\n", rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			fprintf(ft, "%lf ", arr[i][j]);
		}
		fprintf(ft, "\n");
	}
		
	fclose(ft);

	return 0;
}
int array_saver_binary(double arr[ROWS][COLS], int rows, int cols, char *fileName) {

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
