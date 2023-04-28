#include <stdio.h>
#include <stdlib.h>

#define TERMINAL_VALUE -1

struct raggedArr {
	int** data=NULL;	
};

void array_init(raggedArr ragArr);
void memory_release(raggedArr ragArr);

int get_rows(int &rows);

int fill_mode(raggedArr ragArr, int &mainRows, int &mainCols);
int output_mode(raggedArr ragArr, int rows, int cols);

void array_user_fill(raggedArr ragArr, int rows, int cols); 

int get_len(int *stringArr);

int array_read_txt(raggedArr ragArr, int &rows, int &cols, char *fileName);
int array_read_binary(raggedArr ragArr, int &rows, int &cols, char *fileName);

void array_screen_print(raggedArr ragArr);
int array_save_txt(raggedArr ragArr, int rows, int cols, char *fileName);
int array_save_binary(raggedArr ragArr, int rows, int cols, char *fileName);
