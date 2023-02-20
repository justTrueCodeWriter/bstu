#include <stdio.h>

//fuctions init
int task1(), task2();

//array of pointer of functions init
int (*opts[2])() = {
	task1,
	task2
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

