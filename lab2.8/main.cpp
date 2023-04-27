#include "stdio.h"

#include "ragged_arr.h"

struct raggedArr {
	char** data=NULL;	
}ragArr;

int main() {

	int errorStatus, outputCheck;
	int mainRows, mainCols;	

	array_init(ragArr.data);

	printf("%d", get_len(*ragArr.data));

	errorStatus = fill_mode(ragArr.data, mainRows, mainCols);
	if (errorStatus == -1) {
		return -1;
	}

	//array_screen_print(ragArr.data);

	output_mode(ragArr.data, mainRows, mainCols);
	
	return 0;

}
