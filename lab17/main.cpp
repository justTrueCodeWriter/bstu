#include <stdio.h>
#include <stdlib.h>
#define ROWS 100
#define COLS 100

int amount();

int fill_mode(int arr[ROWS][COLS], int &rows, int &cols);
int output_mode(int arr[ROWS][COLS], int rows, int cols);

void user_array_filler(int arr[ROWS][COLS], int &rows, int &cols); 
int array_reader_txt(int arr[ROWS][COLS], char *fileName);
int array_reader_binary(int arr[ROWS][COLS], char *fileName);
int random_array_filler(int arr[ROWS][COLS]);
int formula_array_filler(int arr[ROWS][COLS]);

void screen_array_printer(int arr[ROWS][COLS], int rows, int cols);
int array_saver_txt(int arr[ROWS][COLS], int rows, int cols, char *fileName);
int array_saver_binary(int arr[ROWS][COLS], int rows, int cols, char *fileName);

int main() {

	int arr[ROWS][COLS];
	int amountOfElements, outputCheck;
	int rows, cols;	
	amountOfElements = fill_mode(arr, rows, cols);

	if (amountOfElements == 0)
		return 0;

	output_mode(arr, rows, cols);
	
	return 0;

}

int fill_mode(int arr[ROWS][COLS], int &rows, int &cols){

	int userChoice, amountOfElements;
	char textFileName[]="src.txt", binFileName[]="src.bin";
// FILL MODE
	do {
		printf("Select the array fill mode:\nUser input(1)\nArray from text file(2)\nArray from binary file(3)\nRandom fill(4)\nFormula fill(5)\n> "); 
		scanf("%d", &userChoice);
		switch (userChoice) {
			case 1: amountOfElements = amount(); // AMOUNT OF STUDENTS
					user_array_filler(arr, rows, cols);
					break;

			case 2: amountOfElements = array_reader_txt(arr, textFileName);	
					if (amountOfElements == 0)
						return 0;
					break;

			case 3: amountOfElements = array_reader_binary(arr, binFileName);
					if (amountOfElements == 0)
						return 0;
					break;
			case 4: amountOfElements = random_array_filler(arr);
					break;
			case 5: amountOfElements = formula_array_filler(arr); 
					break;

			default: printf("Mode must satisfy (1 <= choice <= 5)\n");
		}
	}while((userChoice < 1)||(userChoice > 5));

	return amountOfElements;
}
int output_mode(int arr[ROWS][COLS], int rows, int cols){

	int userChoice, errorStatus;

	char textFileName[]="src.txt", binFileName[]="src.bin";
// OUTPUT MODE
	do {
		printf("Select the array output mode:\nPrint on screen(1)\nSave to text file(2)\nSave to binary file(3)\n> "); 
		scanf("%d", &userChoice);
		switch (userChoice) {
			case 1: screen_array_printer(arr, rows, cols); // AMOUNT OF STUDENTS
					break;

			case 2: errorStatus  = array_saver_txt(arr, rows, cols, textFileName);	
					if (errorStatus == 0)
						return 0;
					break;

			case 3: errorStatus = array_saver_binary(arr, rows, cols, binFileName);
					if (errorStatus == 0)
						return 0;
					break;


			default: printf("Mode must satisfy (choice = 1 or choice = 2 or choice = 3)\n");
		}
	}while((userChoice != 1)||(userChoice != 2)||(userChoice != 3));

	return 0;
}

// FILLING BY USER
void user_array_filler(int *arr, int &rows, int &cols) {
	do {
		printf("rows"); scanf("%d", &rows);		
		printf("cols"); scanf("%d", &cols);		
		if ((rows<1)||(cols<1))
			printf("INCORRECT: rows and cols must satisfy (rows > 0 and cols > 0)");
	}while((rows<1)||(cols<1));

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf(""); scanf("%d", &arr[i][j]);
		}
		printf("\n");
	}
			

}

