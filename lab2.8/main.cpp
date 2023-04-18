#include "stdio.h"

#include "regged_arr.h"

struct reggedArray {
	char** data;
	
};

int main() {

	int errorStatus, outputCheck;
	int mainRows, mainCols;	



	errorStatus = fill_mode(arr, mainRows, mainCols);
	if (errorStatus == -1) {
		return -1;
	}

	array_screen_print(arr);

	output_mode(arr, mainRows, mainCols);
	
	return 0;

}
