#include <stdio.h>
#include <malloc.h>
#include "list.h"


void init_single_list(int n, Student& head);

void fill_single_list(Student& head);

void init_single_list(int n, Student& head) {

	if (n > 0) {
		head.next = (Student*)malloc(sizeof(Student));

		fill_single_list(head);

		head.next = NULL;

		init_single_list(n-1, head);	

	}

}

void fill_single_list(Student& head) {

	fgets(head.surname, SURNAME_BUFFER, stdin);			

	scanf("%c%c", &head.year, &head.group);	

	for (int i = 0; i < 5; i++) {
		scanf("%c", &head.marks[i]);
	}

}
