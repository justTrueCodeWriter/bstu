#include <stdio.h>

/*8. Даны радиусы семи окружностей. Определить количество
окружностей, у которых площадь больше 20.*/

int circle_area(int r);

int task2() {
	int r, counter = 0;
	double s;

	for (int i = 0; i < 7; i++) {
		printf("s%d = ", i+1); scanf_s("%d", &r);
		s = circle_area(r);
		if (s > 20)
			counter++;
	}
	printf("%d\n", counter);
	return 0;

}

int circle_area(int r) {
	double s;

	s = 3.14 * r * r;

	return s;

}