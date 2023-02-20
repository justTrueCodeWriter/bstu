#include <stdio.h>

//Task1
/*8. Даны три числа. Определить их: среднее арифметическое, среднее
гармоническое, сумму, минимальное из них (на выбор
пользователя).*/
int task1() {

	int a, b, c, userChoice, sum, min;
	double  average, harmonicMean;

	printf("a = "); scanf_s("%d", &a);
	printf("b = "); scanf_s("%d", &b);
	printf("c = "); scanf_s("%d", &c);

	printf("Enter type of operation: Average(1), Harmonic Mean(2), Sum(3), Min among 3 numbers(4)\n>>>");
	scanf_s("%d", &userChoice);

	switch (userChoice) {

	case 1:
		average = (a + b + c) / 3.0;
		printf("%lf\n", average);
		break;

	case 2:
		harmonicMean = 3.0 / ((1.0 / a) + (1.0 / b) + (1.0 / c));
		printf("%lf\n", harmonicMean);
		break;

	case 3:
		sum = a + b + c;
		printf("%d\n", sum);
		break;

	case 4: 
		min = a;

		if (min > b) min = b;
		if (min > c) min = c;

		printf("%d\n", min);
		break;

	default: printf("Incorrect input!\n");

	}

	return 0;

}