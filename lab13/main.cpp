#include <stdio.h>
#include <stdlib.h>
#include <ctime>

double average(int mixedArray[], int amountOfElements); 
int elements_array_mixer(int array[], int mixedArray[], int amountOfElements), user_array_filler(int array[], int amountOfElements), random_array_filler(int array[], int boundA, int boundB, int amountOfElements);

int main() {

	int userChoice, amountOfElements, array[]{}, mixedArray[]{}, A, B;
	int averageResult;

	printf("Select the array fill mode:\nUser input(1)/Random fill(2)"); 
	scanf("%d", &userChoice);

	do {
		printf("Amount of elements = ");	scanf("%d", &amountOfElements);

		if (amountOfElements < 0)
			printf("Amount of elements must satisfy (n>0)\n");
	}while(amountOfElements < 0);

	amountOfElements--;

	if (userChoice == 1) {
		user_array_filler(array, amountOfElements);
		elements_array_mixer(array, mixedArray, amountOfElements);
	}
	else {
		printf("A = "); scanf("%d", &A);
		printf("B = "); scanf("%d", &B);

		random_array_filler(array, A, B, amountOfElements);
		elements_array_mixer(array, mixedArray, amountOfElements);
	}

	averageResult = average(mixedArray, amountOfElements);

	printf("Correct main\n");

	printf("result = %d\n", averageResult);

	printf("Finished\n");
	
	return 0;

}

int user_array_filler(int array[], int amountOfElements) {

	for (int i = 0; i <= amountOfElements; i++) {
		printf("array[%d] = ", i);
		scanf("%d", &array[i]);
	}

	printf("Correct user\n");

	for (int i = 0; i <= amountOfElements; i++) {
		printf("%d ", array[i]);
	}

	return 0;

}

int random_array_filler(int array[], int boundA, int boundB, int amountOfElements) {

	for (int i = 0; i <= amountOfElements; i++)	
		array[i] = rand() % (boundB - boundA + 1) + boundA;

	printf("Correct random\n");

	for (int i = 0; i <= amountOfElements; i++) {
		printf("%d ", array[i]);
	}

	return 0;

}

int elements_array_mixer(int array[], int mixedArray[], int amountOfElements) {

	for (int i = 0, j = 0; i <= amountOfElements; i++, j+=2) {
		mixedArray[j] = array[i+1];
		mixedArray[j+1] = array[i];
	}

	printf("Correct mixer\n");

	for (int i = 0; i <= amountOfElements; i++) {
		printf("%d ", mixedArray[i]);
	}

	return 0;	

}

double average(int mixedArray[], int amountOfElements) {

	double sumAndAverage = 0;		
	for (int i = 0; i <= amountOfElements; i++) {
		sumAndAverage += mixedArray[i];
	}

	sumAndAverage /= amountOfElements + 1;

	printf("Correct average\n");

	return sumAndAverage;

}
