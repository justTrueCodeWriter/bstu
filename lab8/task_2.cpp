#include <stdio.h>

/*21. Дано целое положительное число. Определить на сколько сумма
цифр, стоящих на нечетных позициях, меньше самого числа.*/
int task_2() {

	int n, initialNumber, res = 0, sum = 0, flag = 0;

	do {
		printf("n = "); scanf_s("%d", &n);
	
		if (n > 0) {
			flag = 1;
		}
	} while ((flag != 1) && (n != -777));

	initialNumber = n;
	
	while (n > 0) {
		sum += n % 10;
		n /= 100;
	}
	res = initialNumber - sum;
	printf("result = %d\n", res);

	return 0;

}