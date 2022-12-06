#include <stdio.h>

int main() {

    int n, m, flag = 0;
    double a, b, composition = 1, summ = 0;
    do {
        printf("n = "); scanf_s("%d", &n);
        printf("m = "); scanf_s("%d", &m);
        printf("a = "); scanf_s("%lf", &a);
        printf("b = "); scanf_s("%lf", &b);

        if ((n > 0) && (m > 0))
            flag = 1;
        else
            printf("n and m must satisfy (n > 0 and m > 0)\n");
    } while (flag != 1);

    for (int i = 1; i <= n; i++) {
        composition = 1;
        for (int j = 0; j <= m; j++)
            composition *= (a + b * j);
        summ += i + composition;
    }
    printf("%lf", summ);

    return 0;

}
