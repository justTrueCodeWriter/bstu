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
			printf("Mode:\nScan num(1)\nPull element(2)\nPrint elements(3)\nSqr elements(4)\nClear queue(5)\nExit(6)\n> "); scanf("%d", &userChoice);
			switch (userChoice) {
				case 1: scan_number(queue_field, length); break;
				case 2: pull(queue_field); break;
				case 3:	print_queue(queue_field); break; 
				case 4: sqr_evens(queue_field, sqrElements, sqrCount);
						print_queue(queue_field);
						print_evens(sqrElements, sqrCount);
						sqrCount=0;
						break;
				case 5: clear_queue(queue_field, length); break;
				case 6: return;
				default: printf("Incorrect choice!\n");
			}
		}while((userChoice>=1)&&(userChoice<=6));
	}
}

void scan_number(Queue& q, int &length) {

		int element, numberOfElements;

		do {
			printf("Number of elements "); scanf("%d", &numberOfElements);
		}while(numberOfElements<=0);

		for (int i=0; i < numberOfElements; i++) {
			printf("n%d = ", i); scanf("%d", &element);
			push(q, element);
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
