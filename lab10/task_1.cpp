#include <stdio.h>

int task_1() {

	int a, b, n, m, summ = 0, composition = 1;

	printf("n = "); scanf("%d", &n);
	printf("m = "); scanf("%d", &m);
	printf("a = "); scanf("%d", &a);
	printf("b = "); scanf("%d", &b);

	for(int i = 1; i <= n; i++) {
		composition = 0;
		for(int j = 0; j <= m; j++)
			composition *= (a + b*j);
		summ += i + composition;
	}	
	printf("%d", summ);

	return 0;

}

int main() {

	task_1();

}
