#include <stdio.h>
int task_1() {

    int n, st = 1;
    double s = 0, x;

    printf("n = "); scanf("%d", &n);
    printf("x = "); scanf("%lf", &x);

    for (int i = 1; i <= n; i++) {
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
