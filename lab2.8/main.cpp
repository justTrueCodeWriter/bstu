#include "ragged_arr.h"

int main() {

	int errorStatus, outputCheck;
	int mainRows, mainCols;	

	raggedArr ragArr;	

	array_init(ragArr);

	array_user_fill(ragArr, mainRows, mainCols);
	array_screen_print(ragArr);
	memory_release(ragArr);

	//errorStatus = fill_mode(ragArr.data, mainRows, mainCols);
	if (errorStatus == -1) {
		return -1;
	}

	//array_screen_print(ragArr.data);

	//output_mode(ragArr.data, mainRows, mainCols);
	
	return 0;

}
