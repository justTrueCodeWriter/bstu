#include <stdio.h>
#include <stdlib.h>
#include <ctime>

#define SIZE 100

double average(int array[], int amountOfElements); 
int elements_array_mixer(int array[], int amountOfElements), user_array_filler(int array[], int amountOfElements), random_array_filler(int array[], int boundA, int boundB, int amountOfElements);

int main() {

	int userChoice, amountOfElements, array[SIZE]{}, A, B;
	double averageResult;

	do {
		printf("Select the array fill mode:\nUser input(1)/Random fill(2):"); 
		scanf("%d", &userChoice);
		if ((userChoice != 1)&&(userChoice != 2))
			printf("Mode must satisfy (choice = 1 or choice = 2)\n");
	}while((userChoice != 1)&&(userChoice != 2));

	do {
		printf("Amount of elements = ");	scanf("%d", &amountOfElements);

		if (amountOfElements < 0)
			printf("Amount of elements must satisfy (n>0)\n");
	}while(amountOfElements < 0);

	amountOfElements--;

	if (userChoice == 1) {
		user_array_filler(array, amountOfElements);
		elements_array_mixer(array,amountOfElements);
	}
	else {
		do {
			printf("A = "); scanf("%d", &A);
			printf("B = "); scanf("%d", &B);
			if (A > B) 
				printf("A and B must satisfy (A<B)\n");
		}while(A > B);

		random_array_filler(array, A, B, amountOfElements);
		elements_array_mixer(array, amountOfElements);
	}

	averageResult = average(array, amountOfElements);

	printf("result = %.3lf\n", averageResult);

	return 0;

}

int user_array_filler(int array[], int amountOfElements) {

	for (int i = 0; i <= amountOfElements; i++) {
		printf("array[%d] = ", i);
		scanf("%d", &array[i]);
	}

	for (int i = 0; i <= amountOfElements; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;

}

int random_array_filler(int array[], int boundA, int boundB, int amountOfElements) {

	for (int i = 0; i <= amountOfElements; i++)	
		array[i] = rand() % (boundB - boundA + 1) + boundA;

	for (int i = 0; i <= amountOfElements; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;

}

int elements_array_mixer(int array[], int amountOfElements) {

	int element;
	for (int i = 0; i < amountOfElements; i+=2) {
		element = array[i];
		array[i] = array[i+1];
		array[i+1] = element;
	}

	for (int i = 0; i <= amountOfElements; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;	

}

double average(int array[], int amountOfElements) {

	double sumAndAverage = 0;		
	for (int i = 0; i <= amountOfElements; i++) {
		sumAndAverage += array[i];
	}

	amountOfElements++;
	sumAndAverage /= amountOfElements;

	return sumAndAverage;

}
