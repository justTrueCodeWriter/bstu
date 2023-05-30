#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define BUFFER 100

void list_operations();

void average_group_mark(List& list);

void check_oldest_students(List& list);
void check_youngest_students(List& list);

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
Pull back(5)\nPull position(6)\nAverage mark(7)\nLargest group(8)\nOldest & youngest(9)\nPrint list(10)\nClear list(11)\nExit(12)\n> "); scanf("%d", &userChoice);
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
				case 7: average_group_mark(list_field);  break;
				case 8: check_largest_group(list_field); break;
				case 9: check_oldest_students(list_field); 
						check_youngest_students(list_field);
						break;
				case 10:	print_list(list_field); break; 
				case 11: clear_list(list_field); break;
				case 12: clear_list(list_field); return; break;
				default: printf("Incorrect choice!\n");
			}
		}while((userChoice>=1)&&(userChoice<=12));
	}

	

}

int group_amount(List& list) {

	int groupsAmount = 0; 
	int groupCopy = 0;

	for (Student * cur = list.head; cur != nullptr; cur = cur->next) {
		groupsAmount++;
	}

	printf("groupsAmount %d\n", groupsAmount);

	for (Student * mainCheck = list.head; mainCheck != nullptr; mainCheck = mainCheck->next) {
		for (Student * curCheck = mainCheck->next; curCheck != nullptr; curCheck = curCheck->next)	{
					
			if ((mainCheck->year == curCheck->year)&&(mainCheck->group == curCheck->group))	{
				groupsAmount--;
				break;
			}
		}

	}

	return groupsAmount;

}

void checkUnique(List& list, int *checkedYear, int *checkedGroup, int groupsAmount) {

	int j = 0, inCount = 0;
	for (Student * curMain = list.head; curMain != nullptr; curMain = curMain->next) {
		for (int i = 0; i < groupsAmount; i++) {
			if ((curMain->year == checkedYear[i])&&(curMain->group == checkedGroup[i])) {
				j++;
				break;	
			}
			if ((curMain->year != checkedYear[i])&&(curMain->group != checkedGroup[i])) {
				checkedYear[j] = curMain->year;
				checkedGroup[j] = curMain->group;
				j = 0;
			}
		}
	}

}

void average_group_mark(List& list) {

	int groupsAmount;

	groupsAmount = group_amount(list);

	printf("Group amount = %d\n", groupsAmount);

	int checkedYear[groupsAmount];
	int checkedGroup[groupsAmount];

	checkUnique(list, checkedYear, checkedGroup, groupsAmount);

	printf("Unique\n");

	for (int i = 0; i < groupsAmount; i++)
		printf("Year = %d, group = %d\n", checkedYear[i], checkedGroup[i]);

	float subjects[groupsAmount][MARKS_SIZE];

	int j;
	for (int i = 0; i < groupsAmount; i++) {
		j = 0;
		for (Student * curCheck = list.head; curCheck != nullptr; curCheck = curCheck->next)	{
						
			if ((checkedYear[i] == curCheck->year)&&(checkedGroup[i] == curCheck->group))	{
				subjects[i][j] = curCheck->marks[i];
			}
			j++;
		}
		//for (Student * curCheck)
	}			
		

}

void check_oldest_students(List& list) {

	int oldest = 0; 

	for (Student * mainCheck = list.head; mainCheck != nullptr; mainCheck = mainCheck->next) {
		if (mainCheck->year > oldest) {
			oldest = mainCheck->year;	
		}
	}

	Student oldestStudents[BUFFER];
	int i = 0, oldestCount = 0;
	for (Student * cur = list.head; cur != nullptr; cur = cur->next) {
	
		if (cur->year == oldest) {
			oldestStudents[i] = *cur;
			oldestCount++;
			i++;
		}
	}

	printf("OLDEST:\n");

	for (int j = 0; j<oldestCount; j++) {
		printf("Surname: %s\nYear: %d\nGroup: %d\n", oldestStudents[j].surname, oldestStudents[j].year, oldestStudents[j].group);
	}	
	printf("\n");

}

void check_youngest_students(List& list) {

	int youngest = 10; 

	for (Student * mainCheck = list.head; mainCheck != nullptr; mainCheck = mainCheck->next) {
		if (mainCheck->year < youngest) {
			youngest = mainCheck->year;	
		}
	}

	Student youngestStudents[BUFFER];
	int i = 0, youngestCount = 0;
	for (Student * cur = list.head; cur != nullptr; cur = cur->next) {
	
		if (cur->year == youngest) {
			youngestStudents[i] = *cur;
			youngestCount++;
			i++;
		}
	}

	printf("YOUNGEST:\n");

	for (int j = 0; j<youngestCount; j++) {
		printf("Surname: %s\nYear: %d\nGroup: %d\n", youngestStudents[j].surname, youngestStudents[j].year, youngestStudents[j].group);
	}
	printf("\n");

}

void check_largest_group(List& list) {

	int groupSize = 0, largest = 0; 
	int largestYear = 0, largestGroup = 0;

	for (Student * mainCheck = list.head; mainCheck != nullptr; mainCheck = mainCheck->next) {
		groupSize = 0;
		for (Student * curCheck = list.head; curCheck != nullptr; curCheck = curCheck->next)	{
					
			if ((mainCheck->year == curCheck->year)&&(mainCheck->group == curCheck->group))	{
				groupSize++;
			}
		}
		
		if (groupSize > largest) {
			largest = groupSize;	
			largestYear = mainCheck->year;
			largestGroup = mainCheck->group;
		}
	}
	//printf("largest=%d | checkedElemSize=%d\n", largest, checkedElemSize);
	printf("Year: %d\nGroup: %d\n", largestYear, largestGroup);

}
