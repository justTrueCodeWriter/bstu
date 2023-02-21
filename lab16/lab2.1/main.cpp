/*1. Определить максимальное и минимальное значения из двух различных вещественных чисел.*/

#include <stdio.h>

int main() {

	float number1, number2;
	float *maximum, *minimum;

	printf("number1 = "); scanf("%f", &number1);
	printf("number2 = "); scanf("%f", &number2);

	if (number1 < number2) {
		maximum = &number2;
		minimum = &number1;
	}
	else {
		maximum = &number1;
		minimum = &number2;
	}

	printf("max = %.3f\nmin = %.3f\n", *maximum, *minimum);
		
}
