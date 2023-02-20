#include <stdio.h>

/*21. Вычислить значения выражений z для значений x, равных 5,
10, …, 100: z = 6f^2− 2f, f = 2x−1.*/
int task_1() {

	int z, f = 0;

	for (int x = 100; x >= 5; x -= 5) {
		z = 6 * f * f - 2 * f;
		f = 2 * x - 1;
		printf("x = %d, z = %d\n", x, z);
	}
	return 0;

}