#include <stdio.h>
#include <stdlib.h>
#include <ctime>

#define SIZE 100

double average(int array[], int amountOfElements); 

int amount(), input_file(int array[]);

void user_array_filler(int array[], int amountOfElements), 
	 random_array_filler(int array[], int boundA, int boundB, int amountOfElements),
	 elements_array_mixer(int array[], int amountOfElements), 
	 output_file(int array[], int amountOfElements);

int main() {
	
	int userChoice, isCorrectArrMode, amountOfElements, array[SIZE]{}, A, B;
	double averageResult;

// ARRAY FILL MODE
	do {	
		isCorrectArrMode = 0;
		printf("Select the array fill mode:\nUser input(1)/Random fill(2)/From file(3):"); 
		scanf("%d", &userChoice);

		switch (userChoice) {
			case 1:
				amountOfElements = amount();
				user_array_filler(array, amountOfElements);
				break;
			case 2:
				amountOfElements = amount();
				do {
					printf("A = "); scanf("%d", &A);
					printf("B = "); scanf("%d", &B);
					if (A > B) 
						printf("A and B must satisfy (A<B)\n");
				}while(A > B);

				random_array_filler(array, A, B, amountOfElements);
				break;
			case 3:
				amountOfElements = input_file(array);
				break;
			default:
				printf("Mode must satisfy (choice = 1 or choice = 2 or choice = 3)\n");
				isCorrectArrMode = 1;
		}
	}while(isCorrectArrMode==1);

	if (amountOfElements == 0)
		return 0;

	elements_array_mixer(array,amountOfElements);

	output_file(array, amountOfElements);

	averageResult = average(array, amountOfElements); // RESULT

	printf("result = %.3lf\n", averageResult);

	return 0;

}

// AMOUNT OF ELEMENTS IN ARRAY
int amount() {
	int amountOfElements;

	do {
		printf("Amount of elements = ");	scanf("%d", &amountOfElements);

		if (amountOfElements < 0)
			printf("Amount of elements must satisfy (n>0)\n");
		}while(amountOfElements < 0);

		return amountOfElements;

}

// USER ELEMENTS ARRAY FILLING
void user_array_filler(int array[], int amountOfElements) {

	for (int i = 0; i < amountOfElements; i++) {
		printf("array[%d] = ", i);
		scanf("%d", &array[i]);
	}

	for (int i = 0; i < amountOfElements; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");

}

// RANDOM ELEMENTS ARRAY FILLING
void random_array_filler(int array[], int boundA, int boundB, int amountOfElements) {

	for (int i = 0; i < amountOfElements; i++)	
		array[i] = rand() % (boundB - boundA + 1) + boundA;

	for (int i = 0; i < amountOfElements; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");

}

// ELEMENTS ARRAY MIXING
void elements_array_mixer(int array[], int amountOfElements) {

	int element;
	for (int i = 0; i < amountOfElements; i+=2) {
		element = array[i];
		array[i] = array[i+1];
		array[i+1] = element;
	}

}

// AVERAGE OF ELEMENTS
double average(int array[], int amountOfElements) {

	double sumAndAverage = 0;		
	for (int i = 0; i < amountOfElements; i++) {
		sumAndAverage += array[i];
	}

	sumAndAverage /= amountOfElements;

	return sumAndAverage;

}

// SCAN ARRAY FROM FILE AND RETURN AMOUNT FROM FILE
int input_file(int array[])
{
	int amountOfElements;
	FILE *ft;
	ft=fopen("src.txt","rt");
	if (ft == 0) {
		printf("ERROR");
		return 0;
	}
	fscanf(ft, "%d", &amountOfElements);
	for(int i=0; i < amountOfElements; i++)
		fscanf(ft,"%d",&array[i]);
	fclose(ft);

	return amountOfElements;

}

// WRITE ARRAY IN FILE
void output_file(int array[], int amountOfElements)
{
	FILE* f=fopen("log.txt","w+");
	fprintf(f,"%d ",amountOfElements);
	for(int i=0; i < amountOfElements; i++)
		fprintf(f,"%d ",array[i]);
	fclose(f);
}
