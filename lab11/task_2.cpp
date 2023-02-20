#include <stdio.h>
#include <math.h>
int task_2() {

    int stl = -1, i = 1, k = 1;
    double s = 0, x, stx, e, sl, f = 1;

    printf("x = "); scanf("%lf", &x);
    printf("e = "); scanf("%lf", &e);
    stx = x;

    do {
        printf("i = %d\n", i);
        while(k <= i) {
            k++;
            x *= x;
        }

        sl = stl * stx / f;
        s += sl;
        i++;
        stx *= x;
        stl *= -1;
        f *= (-1)*(2 * i + 3);
    } while (fabs(sl) > e);
    printf("%lf", s);

    return 1;

}

int main() {

	task_2();

	return 0;

}
