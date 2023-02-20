#include <stdio.h>
#include <math.h>

int task_2() {

	int C, flag = 0;
	double A, B, result;

	do {
		printf("A = "); scanf_s("%lf", &A);
		printf("B = "); scanf_s("%lf", &B);
		printf("C = "); scanf_s("%d", &C);

		if (C > 0)
			flag = 1;
		else
			printf("n and m must satisfy (n > 0 and m > 0)\n");
	} while (flag != 1);


	for (int i = A; i <= B; i += C) {

		if (i < -1) {
			result = 2 * i + 5;
		}

		else if (i <= 10) {
			result = sin(i);
		}

		else {
			result = 2 * (cos(i) / sin(i));
		}

		printf("f(x) = %lf\n", result);

	}
	

	return 0;

}