#include <stdio.h>
#include "stack.h"

//extern Stack stack_field;

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

	bool isStackCleared = true;
	

	while (true) {
		do {	
			printf("Mode:\nScan num(1)\nPrint elements(2)\nSum elements(3)\nProduct elements(4)\nClear stack(5)\nExit(6)\n> "); scanf("%d", &userChoice);
			switch (userChoice) {
				case 1: scan_number(stack_field, length); 
						isStackCleared = false; 
						break;
				case 2:	if (!isStackCleared) print_stack(stack_field); 
							break; 
				case 3: if (!isStackCleared) sum_elements(stack_field); 	
							break;
				case 4: if (!isStackCleared) product_elements(stack_field); 
						break;
				case 5: if (!isStackCleared) {
							clear_stack(stack_field); 
							isStackCleared = true;
						}
						break;
				case 6: return;
				default: printf("Incorrect choice!\n");
			}
		}while((userChoice>=1)&&(userChoice<=6));
	}
}

void scan_number(Stack& s, int &length) {

		int tmp=0;
		int number, numberTmp;

		printf("n = "); scanf("%d", &number);

		numberTmp = number;

		for (; numberTmp != 0; length++) {
			tmp = numberTmp % 10;
			numberTmp /= 10;
		}
		
		init_stack(s, length);

		printf("Correct init\n");

		while (number != 0) {
			tmp = number % 10;
			number /= 10;
			push(s, tmp);
		}
}

void sum_elements(Stack& s) {

	int summ=0;

	for (int i = 0; i <= s.top; i++) {
		summ+=s.elements[i];
	}

	printf("Summ = %d\n", summ);

}

void product_elements(Stack& s) {

	int prod=1;

	for (int i = 0; i <= s.top; i++) {
		prod*=s.elements[i];
	}

	printf("Product = %d\n", prod);

}
