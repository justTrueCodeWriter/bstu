#include "ragged_arr.h"

int main() {

	int errorStatus, outputCheck;
	int mainRows, mainCols;	

	raggedArr ragArr;	

	array_init(ragArr);

	errorStatus = fill_mode(ragArr);
	if (errorStatus == -1) {
		return -1;
	}

	array_screen_print(ragArr);

	output_mode(ragArr);
	
	memory_release(ragArr);
	return 0;

}
