#include <stdio.h>
#include <stdlib.h>

int main() {

	int **arr;

	arr = (int**)malloc(sizeof(int*)*3);
	arr[0] = (int*)malloc(sizeof(int)*5);
	arr[1] = (int*)malloc(sizeof(int)*4);
	arr[2] = (int*)malloc(sizeof(int)*3);


	arr[0][0] = 1;


}
