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
			printf("Mode:\nPush front(1)\nPush back(2)\nPush position(3)\nPull front(4)\nPull back(5)\nPull position(6)\nPrint list(7)\nClear list(8)\nExit(9)\n> "); scanf("%d", &userChoice);
			switch (userChoice) {
				case 1: push_front(list_field); break;
				case 2: push_back(list_field); break;
				case 3: {
							int n;
							printf("Position: "); scanf("%d", &n);
							push_position(n, list_field); break;
						}
				case 4: pull_front(list_field); break;
				case 5: pull_back(list_field); break;
				case 6: {
							int n;
							printf("Position: "); scanf("%d", &n);
							pull_position(n, list_field); break;
						}
				case 7:	print_list(list_field); break; 
				case 8: clear_list(list_field); break;
				case 9: clear_list(list_field); return; break;
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

	int *checkedYear;
	int *checkedGroup;
	
	//for (Student * cur = list.head; cur->next != nullptr; cur = cur->next)
			
}
