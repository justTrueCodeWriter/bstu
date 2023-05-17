#include <stdio.h>
#include <malloc.h>

#include "stack.h"

void push(Stack& s, int d) {

	Element* e = (Element*)malloc(sizeof(Element));
	e->data = d;
	e->next = s.head;
	s.head = e;

}

int pull(Stack& s) {

	if (s.head==NULL) return 0;
	int d = s.head->data;
	Element* e = s.head;	
	s.head = s.head->next;

	free(e);

	return d;

}

void print_stack(Stack& s) {

	printf("Correct print\n");
	for (Element * cur = s.head; cur != NULL; cur = cur->next) {
		printf("%d -> ", cur->data);
	}	
	printf("\b\b\b  \n");

}

void clear_stack(Stack& s, int& length) {
	if (s.head == NULL) return;

// TODO: clear stack
//
	s.head=NULL;	

	length = 0;
}
