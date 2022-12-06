#include <stdio.h>

/*21. Дано целое положительное число. Определить на сколько сумма
цифр, стоящих на нечетных позициях, меньше самого числа.*/
int task_2() {

	int n, count = 0, initialNumber, res = 0, sum = 0, flag = 0;
	
	while (flag != 1) {
		printf("n = "); scanf_s("%d", &n);
		initialNumber = n;

		if (n < 0) {
			printf("n need be n > 0. Try again.\n");
		}
		else {
			while (n > 0) {
				sum += n % 10;
				n /= 100;
			}
			res = initialNumber - sum;
			printf("result = %d\n", res);
			flag = 1;
		}
	}

	return 0;

}