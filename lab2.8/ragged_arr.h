void array_init(char** arr);

int fill_mode(char** arr, int &mainRows, int &mainCols);
int output_mode(char** arr, int rows, int cols);

void array_user_fill(char** arr, int rows, int cols); 

int get_len(char *stringArr);

int array_read_txt(char** arr, int &rows, int &cols, char *fileName);
int array_read_binary(char** arr, int &rows, int &cols, char *fileName);

void array_screen_print(char** arr);
int array_save_txt(char** arr, int rows, int cols, char *fileName);
int array_save_binary(char** arr, int rows, int cols, char *fileName);
