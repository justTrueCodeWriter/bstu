#include <stdio.h>
#include "list.h"

void list_operations();

void average_group_mark(List& list);

void check_oldest_student(List& list);
void check_youngest_student(List& list);

int main() {

	list_operations();

	return 0;

}

void list_operations() {

	List list_field;

	int userChoice = 0;

	while (true) {
		do {	
			printf("Mode:\nPush front(1)\nPush back(2)\nPrint list(3)\nClear list(4)\nExit(5)\n> "); scanf("%d", &userChoice);
			switch (userChoice) {
				case 1: push_front(list_field); break;
				case 2: push_back(list_field); break;
				case 3:	print_list(list_field); break; 
				case 4: clear_list(list_field); break;
				case 5: clear_list(list_field); return; break;
				default: printf("Incorrect choice!\n");
			}
		}while((userChoice>=1)&&(userChoice<=6));
	}

	

}

void average_group_mark() {



}

void check_oldest_student(List& list) {

}

void check_youngest_student(List& list) {

}
