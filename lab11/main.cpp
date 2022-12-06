#include <stdio.h>

int task_1(), task_2();

int (*opts[2])() = {
	task_1,
	task_2
};


int main() {

	int n, answer = 0;

	while (answer != 1) {
		printf("Enter number of task: "); scanf_s("%d", &n);

		(*opts[n - 1])();

		printf("Exit? (1/0): "); scanf_s("%d", &answer);
	}
}
