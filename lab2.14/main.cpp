#include <stdio.h>
#include "stack.h"


void stack_operations();

void scan_number(Stack& s, int &length);

void sum_elements(Stack& s);
void product_elements(Stack& s);

int main() {

	stack_operations();	

	return 0;	

}

void stack_operations() {

	Stack stack_field;

	int userChoice=0;
	int length=0;
	

	while (true) {
		do {	
			printf("Mode:\nScan num(1)\nPrint elements(2)\nSum elements(3)\nProduct elements(4)\nPull element(5)\nClear stack(6)\nExit(7)\n> "); scanf("%d", &userChoice);
			switch (userChoice) {
				case 1: scan_number(stack_field, length); break;
				case 2:	print_stack(stack_field); break; 
				case 3: sum_elements(stack_field); break;
				case 4: product_elements(stack_field); break;
				case 5: pull(stack_field); break;
				case 6: clear_stack(stack_field, length); break;
				case 7: return;
				default: printf("Incorrect choice!\n");
			}
		}while((userChoice>=1));
	}
}

void scan_number(Stack& s, int &length) {

		int tmp=0;
		int number, numberTmp;


		printf("n = "); scanf("%d", &number);

		numberTmp = number;

		int degree = 10;
		for (; numberTmp != 0; length++) {
			tmp = numberTmp % 10;
			numberTmp /= 10;
			degree*=10;
		}
		

		printf("Correct init\n");

		for (int i = 0; i < length; i++) {
			tmp = number % 10;
			number/=10;
			push(s, tmp);
		}
}

void sum_elements(Stack& s) {

	int summ=0;

	for (Element * cur = s.head; cur != NULL; cur = cur->next) {
		summ+=cur->data;
	}

	printf("Summ = %d\n", summ);

}

void product_elements(Stack& s) {

	int prod=1;

	for (Element * cur = s.head; cur != NULL; cur = cur->next) {
		prod*=cur->data;
	}

	printf("Product = %d\n", prod);

}
