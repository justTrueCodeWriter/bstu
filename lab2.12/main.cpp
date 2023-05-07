#include "ragged_arr.h"

extern raggedArr ragArr;
extern raggedArrSorted ragArrSort;

int fill_mode();
int output_mode();
void additional_operations();

int main() {

	int errorStatus, outputCheck;
	int mainRows, mainCols;	

	errorStatus = fill_mode();
	if (errorStatus == -1) {
		return -1;
	}

	array_screen_print();

	output_mode();

	additional_operations();

	memory_release();
	return 0;

}

int fill_mode(){

	int userChoice, errorStatus=0;
	const char *textFileName="src.txt", *binFileName="src.bin";
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

	const char *textFileName="src.txt", *binFileName="src.bin";
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

void additional_operations() {

	int userChoice;

	do {
		printf("Select array operation: Add line(1)\nDelete last line(2)\nSort by rows length(3)\nNothing(4)\n> "); 
		scanf("%d", &userChoice);
		switch (userChoice) {
			case 1: add_last_line(); break;
			case 2: delete_last_line(); break;
			case 3: sort_by_legth(); break;
			case 4: break;
			default: printf("Mode must satisfy (1 <= choice <= 3)\n"); 
		}
	}while((userChoice < 1)||(userChoice > 4));

	array_screen_print();

}
