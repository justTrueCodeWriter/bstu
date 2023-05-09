#include <stdio.h>
#include "queue.h"

//extern Queue queue_field;

void queue_operations();

void scan_number(Queue& q, int &length);

void sqr_evens(Queue& q, int *sqrElements, int &sqrCount);

void print_evens(int *sqrElements, int &sqrCount);

#define SIZE 100

int main() {

	queue_operations();	

	return 0;	

}

void queue_operations() {

	Queue queue_field;

	int sqrElements[SIZE];

	int userChoice=0;
	int length=0;
	int sqrCount = 0;

	while (true) {
		do {	
			printf("Mode:\nScan num(1)\nPrint elements(2)\nSum elements(3)\nClear queue(4)\nExit(5)\n> "); scanf("%d", &userChoice);
			switch (userChoice) {
				case 1: scan_number(queue_field, length); break;
				case 2:	print_queue(queue_field); break; 
				case 3: sqr_evens(queue_field, sqrElements, sqrCount); break;
				case 4: print_queue(queue_field);
						print_evens(sqrElements, sqrCount);
						break;
				case 5: clear_queue(queue_field, length); break;
				case 6: return;
				default: printf("Incorrect choice!\n");
			}
		}while((userChoice>=1));
	}
}

void scan_number(Queue& q, int &length) {

		int tmp=0;
		int number, numberTmp;

		printf("n = "); scanf("%d", &number);

		numberTmp = number;

		for (; numberTmp != 0; length++) {
			tmp = numberTmp % 10;
			numberTmp /= 10;
		}
		

		printf("Correct init\n");

		while (number != 0) {
			tmp = number % 10;
			number /= 10;
			push(q, tmp);
		}
}

void sqr_evens(Queue& q, int *sqrElements, int &sqrCount) {

	int i = 0;
	for (Element * cur = q.head; cur != NULL; cur = cur->next) {
		if (cur->data%2==0) {
			sqrElements[i] = cur->data*cur->data;
			i++;
			sqrCount++;
		}
	}

}

void print_evens(int *sqrElements, int &sqrCount) {

	for (int i = 0; i < sqrCount; i++) {
		printf("%d ", sqrElements[i]);
	}
	printf("\n");

}
