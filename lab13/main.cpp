#include <stdio.h>
#include <stdlib.h>
#include <ctime>

double average(int mixedArray[], int amountOfElements); 
int elements_array_mixer(int array[], int amountOfElements), user_array_filler(int amountOfElements), random_array_filler(int boundA, int boundB, int amountOfElements);

int main() {

	int userChoice, amountOfElements, array[], mixedArray[], A, B;
	double averageResult;

	printf("Select the array fill mode:\nUser input(1)/Random fill(2)"); 
	scanf("%d", &userChoice);

	do {
		printf("Amount of elements = ");	scanf("%d", &amountOfElements);

		if (amountOfElements < 0)
			printf("Amount of elements must satisfy (n>0)\n");
	}while(amountOfElements < 0);

	amountOfElements--;
	array[]

	if (userChoice == 1) {
		*array = user_array_filler(amountOfElements);
		*mixedArray = elements_array_mixer(array, amountOfElements);
	}
	else {
		printf("A = "); scanf("%d", &A);
		printf("B = "); scanf("%d", &B);

		*array = random_array_filler(A, B, amountOfElements);
		*mixedArray = elements_array_mixer(array, amountOfElements);
	}

	averageResult = average(mixedArray, amountOfElements);

	printf("result = %lf", averageResult);
	
	return 0;

}

int user_array_filler(int amountOfElements) {

	int userArray[]={};

	for (int i = 0; i <= amountOfElements; i++) {
		printf("array[%d] = ", i);
		scanf("%d", &userArray[i]);
	}

	return *userArray;

}

int random_array_filler(int boundA, int boundB, int amountOfElements) {

	int random_array[]={};
	for (int i = 0; i <= amountOfElements; i++)	
		random_array[i] = rand() % (boundB - boundA + 1) + boundA;

	return *random_array;

}

int elements_array_mixer(int array, int amountOfElements) {

	int tmp[]={}, idFirst, idSecond;

	for (int i = 0, j = 0; i <= amountOfElements; i++, j+=2) {
		idFirst = array[i+1];
		idSecond = array[i];
		tmp[j] = idFirst;
		tmp[j+1] = idSecond;
	}
	return *tmp;	

}

double average(int mixedArray, int amountOfElements) {

	double sumAndAverage = 0;		
	for (int i = 0; i <= amountOfElements; i++) {
		sumAndAverage += mixedArray;
	}

	sumAndAverage /= amountOfElements + 1;

	return sumAndAverage;

}
