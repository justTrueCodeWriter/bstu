#include <stdio.h>
#include <malloc.h>
#include "list.h"

void push_front(List& list) {

	Student * e = (Student*)malloc(sizeof(Student));

	fill_element(*e);

	e->next = list.head;
	list.head = e;

}

void push_back(List& list) {

	Student * e = (Student*)malloc(sizeof(Student));

	fill_element(*e);

	e->next = nullptr;

	if (list.head == nullptr) 
		list.head = e;
	else {
		Student * cur = list.head;
		while(cur->next != nullptr)
			cur = cur->next;
		cur->next = e;
	}

}

void push_position(int n, List& list) {



}

void pull_front(List& list) {

	if (list.head == nullptr) return;

	Student * e = list.head;
	list.head = list.head->next;

	free(e);

}

void pull_back(List& list) {

	if (list.head == NULL) return;

	Student* e = list.head;	
	list.head = list.head->next;

	free(e);

}

void pull_position(List& list) {



}

void fill_element(Student& e) {

	printf("Surname: "); scanf("%s", e.surname);			

	printf("Year, Group: "); scanf("%d%d", &e.year, &e.group);	

	printf("Marks: ");
	for (int i = 0; i < MARKS_SIZE; i++) {
		scanf("%d", &e.marks[i]);
	}

}

void print_list(List& list) {

	if (list.head != nullptr) {

		printf("------------------------------------------------\n");

		for (Student * cur = list.head; cur != nullptr; cur = cur->next) {
			printf("Surname: %s\n", cur->surname);
			printf("Year: %i\n", cur->year);	
			printf("Group: %i\n", cur->group);	

			printf("Marks: ");
			for (int i = 0; i < MARKS_SIZE; i++) 
				printf("%d ", cur->marks[i]);
			printf("\n\n");
		}

		printf("------------------------------------------------\n");

	}

	else
		printf("\nNothing to display. List is empty!\n\n");

}

void clear_list(List& list) {
	if (list.head == NULL) return;

	while(list.head != NULL) {
		Student* e = list.head;	
		list.head = list.head->next;
		free(e);
	}

}
