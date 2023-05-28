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
		}while((userChoice>=1)&&(userChoice<=10));
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

int checkedElements(List& list, int *checkedYear, int *checkedGroup) {
	int checkedYearIndex=0, checkedGroupIndex=0, size = 0;

	int countIn = 0;

	for (Student * curMain = list.head; curMain != nullptr; curMain = curMain->next)	{
			for (int i = 0; i < countIn+1; i++) {

				printf("Correct checkedYear\n");
				if ((curMain->year != checkedYear[checkedYearIndex])&&(curMain->group != checkedGroup[checkedGroupIndex])) {

					printf("Correct if\n");
					checkedYear[checkedYearIndex] = curMain->year;
					checkedGroup[checkedGroupIndex] = curMain->group;

					printf("%d|%d || %d|%d\n", curMain->year, checkedYear[checkedYearIndex], curMain->group, checkedGroup[checkedGroupIndex]);

					checkedYearIndex++;
					checkedGroupIndex++;
					size++;

				}
			}
			countIn++;
	}

	for (int i = 0; i < size; i++) {
		printf("%d ", checkedYear[i]);
	}

	printf("\n");

	for (int i = 0; i < size; i++) {
		printf("%d ", checkedGroup[i]);
	}

	printf("\n");

	return size;
	
}

void check_largest_group(List& list) {

	int checkedYear[BUFFER];
	int checkedGroup[BUFFER];

	int checkedElemSize=0;

	int groupSize=0, largest=0; 
	int largestYear=0, largestGroup=0;

	checkedElemSize = checkedElements(list, checkedYear, checkedGroup);

	for (int i; i < checkedElemSize; i++) {
		groupSize = 0;
		for (Student * curCheck = list.head; curCheck != nullptr; curCheck = curCheck->next)	{
					
			printf("Correct curCheck\n");
			if ((checkedYear[i] == curCheck->year)&&(checkedGroup[i] == curCheck->group))	{
				groupSize++;
			}
		}
	
		
		if (groupSize > largest) {
			printf("Correct if size\n");
			largest = groupSize;	
			largestYear = checkedYear[i];
			largestGroup = checkedGroup[i];
			printf("Correct if size write\n");
		}
	}
	//printf("largest=%d | checkedElemSize=%d\n", largest, checkedElemSize);
	printf("Largest:%d\nYear: %d\nGroup: %d\n", largest, largestYear, largestGroup);

}
