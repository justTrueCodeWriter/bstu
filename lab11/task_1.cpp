#include <stdio.h>
int task_1() {

    int n, st = 1, flag = 0;
    double s = 0, x;

	do {
		printf("n = "); scanf("%d", &n);

		if (n > 2)	
			flag = 1;
		else
			printf("n must satisfy (n > 2)\n");
	}while(flag != 1);
    printf("x = "); scanf("%lf", &x);

    for (int i = 2; i <= n; i++) {
		printf("i = %d\n", i);
        st += -1;
        s += (1 + x) / (i - 1);
    }

	printf("result = %lf", s);

    return 0;

}

int main() {

	task_1();

	return 0;

}
