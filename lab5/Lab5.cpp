#include <stdio.h>
#include <math.h>

//fuctions init
int task1(), task2_Vol_1(), task2_Vol_2();

//array of pointer of functions init
int (*opts[4])() = {
	task1,
	task2_Vol_1,
	task2_Vol_2
};


int main() {

	//var init
	int n, answer = 0;

	while (answer != 1) {
		printf("Enter number of task: "); scanf_s("%d", &n);

		//call function from array
		(*opts[n - 1])();

		//data input
		printf("Exit? (1/0): "); scanf_s("%d", &answer);
	}
}

//	Task 1
/*21. Даны координаты точки. Определить, какой координатной
четверти принадлежит точка.*/
int task1() {

	double x, y;

	printf("x = "); scanf_s("%lf", &x);
	printf("y = "); scanf_s("%lf", &y);

	if ((x > 0) && y > 0) {
		printf("Points in I coordinate quadrant!\n");
	}

	else if ((x < 0) && (y > 0)) {
		printf("Points in II coordinate quadrant!\n");
	}

	else if ((x < 0) && (y < 0)) {
		printf("Points in III coordinate quadrant!\n");
	}

	else if ((x > 0) && (y < 0)) {
		printf("Points in IV coordinate quadrant!\n");
	}
	return 0;

}

//	Task 2
//	Vol 1 ---------------------------------------------
int task2_Vol_1() {

	int x;
	double result;

	printf("x = "); scanf_s("%d", &x);
	
	if (x < -1) {
		result = 2 * x + 5;
	}

	else if (x <= 10) {
		result = sin(x);
	}

	else {
		result = 2*(cos(x) / sin(x));
	}

	printf("f(x) = %lf\n", result);

	return 0;
}

//	Vol 2 ---------------------------------------
int task2_Vol_2() {

	int x;
	double result;

	printf("x = "); scanf_s("%d", &x);

	if (x < -1) {
		result = 2 * x + 5;
	}

	if (( - 1 <= x) && (x <= 10)) {
		result = sin(x);
	}

	if (x > 10) {
		result = 2 * (cos(x) / sin(x));
	}

	printf("f(x) = %lf\n", result);

	return 0;

}
