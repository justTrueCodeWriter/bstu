#include <stdio.h>
#include <malloc.h>

#include "queue.h"

void push(Queue& q, int d) {

	Element* e = (Element*)malloc(sizeof(Element));
	e->data = d;
	e->next = NULL;

	if (q.head==NULL) {
		q.tail = e;
		q.head = e;
	}

	else {
		q.tail->next = e;
		q.tail = e;
	}

}

int pull(Queue& q) {

	if (q.head == NULL) return 0;

	int d = q.head->data;

	if (q.head==q.tail) q.tail = NULL;

	Element* e = q.head;	
	q.head = q.head->next;

	free(e);

	return d;

}

void print_queue(Queue& q) {

	printf("Correct print\n");
	for (Element * cur = q.head; cur != NULL; cur = cur->next) {
		printf("%d -> ", cur->data);
	}	
	printf("\b\b  \n");

}

void clear_queue(Queue& q, int& length) {
	if (q.head == NULL) return;

// TODO: clear_queue

	q.head=NULL;	

	length = 0;
}
