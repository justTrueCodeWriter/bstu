#include <stdio.h>
#include <stdlib.h>

#define TERMINAL_VALUE -1
struct raggedArr {
	int** data;	
};

int get_rows_len();
int get_cols_len(int row);

void array_init(int rows, int *colsCountArr);
void memory_release();

void rows_cols_user_scan();
void array_user_fill(); 

int array_read_txt(const char *fileName);
int array_read_binary(const char *fileName);

void array_screen_print();
int array_save_txt(const char *fileName);
int array_save_binary(const char *fileName);
