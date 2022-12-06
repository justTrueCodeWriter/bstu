#include <stdio.h>
#include <math.h>

/*21. Дано целое число m>1. Получить наибольшее целое k,
при котором 3**k < m.*/
int task_1() {

	int m, n = 1, k = 0, flag = 0;


	while (flag != 1) {
		printf("m = "); scanf_s("%d", &m);
		if (m <= 1) {
			printf("m need be m > 1. Try again.\n"); 
		}
		else {
			while (n < m) {
				n *= 3;
				k++;
			}
			flag = 1;
		}
	}
	printf("%d\n", k);

	return 0;

}