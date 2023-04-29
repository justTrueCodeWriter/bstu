#include <stdio.h>
#include <stdlib.h>

#define TERMINAL_VALUE -1

struct raggedArr {
	int** data=NULL;	
};

int get_rows_len(raggedArr ragArr);
int get_cols_len(raggedArr ragArr, int row);

void array_init(raggedArr ragArr);
void memory_release(raggedArr ragArr);



int fill_mode(raggedArr ragArr);
int output_mode(raggedArr ragArr);

void array_user_fill(raggedArr ragArr); 

int array_read_txt(raggedArr ragArr, const char *fileName);
int array_read_binary(raggedArr ragArr, const char *fileName);

void array_screen_print(raggedArr ragArr);
int array_save_txt(raggedArr ragArr, const char *fileName);
int array_save_binary(raggedArr ragArr, const char *fileName);
