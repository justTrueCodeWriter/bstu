#include <stdio.h>
#include <math.h>
int task_2() {

    int stl = -1, i = 1, k = 1;
    double summ = 0, x, stx, e, sl, f = 1;

    printf("x = "); scanf("%lf", &x);
    printf("e = "); scanf("%lf", &e);
    stx = 1;

	f = 120;
    do {
        printf("i = %d\n", i);

		stx *= x;

        sl = stl * pow(3, stx) / f;
        summ += sl;
        i++;
        stl *= -1;
        f *= (2 * i + 3)*(2 * i + 2);
    } while (fabs(sl) > e);
    printf("%lf", summ);

    return 1;

}

int main() {

	task_2();

	return 0;

}
