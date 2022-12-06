#include <stdio.h>
#include <math.h>

//fuctions init
int task1(), task2();

//array of pointer of functions init
int (*opts[4])() = {
	task1,
	task2
};


int main() {

	//var init
	int n, answer = 0;

	//Exit check
	while (answer != 1) {
		printf("Enter number of task: "); scanf_s("%d", &n);

		//call function from array
		(*opts[n - 1])();

		//data input
		printf("Exit? (1/0): "); scanf_s("%d", &answer);
	}
}

//	TASK 1 ----------------------
/*21. С начала недели прошло N секунд (N – целое). Определить
количество часов, прошедших с начала последнего дня.*/
//seconds in week = 604800
//seconds in day = 86400
int task1() {

	//var init
	int timeInSeconds;
	double timeInHours;

	//data input
	printf("Time in seconds: "); scanf_s("%d", &timeInSeconds);

	//time computing
	timeInHours = timeInHours / 3600;
	timeInHours = timeInSeconds %24;

	//data output
	printf("%.1lf H\n", timeInHours);

	return 0;

}

//	TASK 2 ------------------------
/*21. Дано шестизначное число. Определить на сколько
произведение цифр, стоящих на нечетных позициях, меньше самого
числа.*/
int task2() {

	//var init
	int i,
		number,
		numberAfterChange = 0,
		numberDivider = 100000,
		product = 1,
		res;

	//data input
	printf("number: "); scanf_s("%d", &number);

	//computing product of discharges
	for (i = 0; i < 3; i++) {

		numberAfterChange = number / numberDivider % 10;
		numberDivider /= 100;
		product *= numberAfterChange;

	}

	x = 123456789;
	x = x / 1000  % 100;

	//computing result
	res = number - product;

	//data output
	printf("%d\n", res);

	return 0;

}
