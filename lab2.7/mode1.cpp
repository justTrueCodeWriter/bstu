// 3. Вычислить сумму наибольшего и наименьшего элементов для каждой строки.

#include <stdio.h>
#include <malloc.h>

void array_fill(int *arrPointer, int rows, int cols);

void find_min(int element, int &min);
void find_max(int element, int &max);
void summer(int *arrPointer, int rows, int cols);

int main() {

	int *arrPointer;

	int rows, cols;

	do {
		printf("rows: "); scanf("%d", &rows);
		printf("elements: "); scanf("%d", &cols);
		if ((rows < 1) || (cols < 1)) {
			printf("INCORRECT: rows and elements must satisfy (element > 0)\n");
		}
	}while((rows<1)||(cols<1));
	
	arrPointer = (int*)malloc(rows*cols * sizeof(int));

	array_fill(arrPointer, rows, cols);	

	summer(arrPointer, rows, cols);

	free(arrPointer);

}

void array_fill(int *arrPointer, int rows, int cols) {

	for (int i = 0; i<rows; i++) {
		for (int j = 0; j<cols; j++) {
			printf("a[%d][%d] = ", i+1, j+1);
			scanf("%d", (arrPointer + i*cols + j));
		}
	}

}

void find_min(int element, int &min) {

	if (element < min) 
		min = element;

}

void find_max(int element, int &max) {

	if (element > max)
		max = element;

}

void summer(int *arrPointer, int rows, int cols) {
	int summ = 0, i = 0, j = 0;
	int min, max, element;

	for (; i < rows; i++) {
		element = *(arrPointer + i*cols + j);
		min = element;
		max = element;

		for (; j < cols; j++) {
			element = *(arrPointer + i*cols + j);
			find_min(element, min);	
			find_max(element, max);
		}
		summ += min + max;
		printf("min [%d]: %d\n", i+1, min);
		printf("max [%d]: %d\n", i+1, max);
		printf("summ [%d]: %d\n", i+1, summ);
		printf("\n");
		summ = 0;
		j = 0;
	}
}

