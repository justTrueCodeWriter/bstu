#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define BUFFER 100

void list_operations();

void average_group_mark(List& list);

void check_oldest_student(List& list);
void check_youngest_student(List& list);

void check_largest_group(List& list);

int main() {

	list_operations();

	return 0;

}

void list_operations() {

	List list_field;

	int userChoice = 0;

	while (true) {
		do {	
			printf("Mode:\nPush front(1)\nPush back(2)\nPush position(3)\nPull front(4)\n\
Pull back(5)\nPull position(6)\nLargest group(7)\nPrint list(8)\nClear list(9)\nExit(10)\n> "); scanf("%d", &userChoice);
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
							pull_position(n, list_field); 
						} break;
				case 7: check_largest_group(list_field); break;
				case 8:	print_list(list_field); break; 
				case 9: clear_list(list_field); break;
				case 10: clear_list(list_field); return; break;
				default: printf("Incorrect choice!\n");
			}
		}while((userChoice>=1)&&(userChoice<=6));
	}

	

}

void average_group_mark() {

	int checkedYear[BUFFER];
	int checkedGroup[BUFFER];

}

void check_oldest_student(List& list) {



}

void check_youngest_student(List& list) {

	int checkedYear[BUFFER];
	int checkedGroup[BUFFER];
	
	//for (Student * cur = list.head; cur->next != nullptr; cur = cur->next)
			
}

void check_largest_group(List& list) {

	int checkedYear[BUFFER], checkedYearIndex=0;
	int checkedGroup[BUFFER], checkedGroupIndex=0;

	int groupSize, largest=0; 
	Student *largestGroupPointer;

	for (Student * curMain = list.head; curMain != nullptr; curMain = curMain->next)	{
		groupSize = 0;
		for (int i = 0; checkedYear[i] != 0; i++) {
			if ((curMain->year != checkedYear[i])&&(curMain->group != checkedGroup[i])) {

				checkedYear[checkedYearIndex] = curMain->year;
				checkedYearIndex++;

				checkedGroup[checkedGroupIndex] = curMain->group;
				checkedGroupIndex++;

				for (Student * curCheck = list.head; curCheck != nullptr; curCheck = curCheck->next)	{
					if ((curMain->year == curCheck->year)&&(curMain->group == curCheck->group))	{
						groupSize++;
					}
				}
			}
		}
		if (groupSize > largest) {
			largest = groupSize;	
			largestGroupPointer = curMain;
		}
	}

	printf("Largest:\nYear: %d\nGroup: %d\n", largestGroupPointer->year, largestGroupPointer->group);

	largestGroupPointer = nullptr;

}
