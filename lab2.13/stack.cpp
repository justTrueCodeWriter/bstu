#include <stdio.h>
#include <malloc.h>

#include "stack.h"


void init_stack(Stack& s, int l) {

	if ((s.elements=(int*)malloc(sizeof(int)*l))) {
		s.l = l;
	}
	else s.l = -1;
	s.top=-1;

}

void destruct(Stack& s) {

	if(s.elements) free(s.elements);
	s.l=-1;
	s.top=-1;

}

int push(Stack& s, int d) {

	if(s.top>=s.l-1) return 0;
	s.top++;
	s.elements[s.top]=d;
	return 1;

}

void push_arr1(Stack& s, int* mas, int n) {


	if (s.elements != NULL)	
		free(s.elements);

	s.top=n-1;
	s.l = n;
	s.elements = mas;

}

void push_arr2(Stack& s, int* mas, int n) {

	for (int i = 0; i < n; i++) {
		if (s.top >= s.l-1)
			break;
		s.top++;
		s.elements[s.top] = mas[i];
	}

}

int pull(Stack& s) {

	s.top--;

	if(s.top>=0) return s.elements[s.top];
	else return 1;

}

void print_stack(Stack& s) {

	printf("Correct print\n");
	for (int i = 0; i <= s.top; i++) {
		printf("%d <- ", s.elements[i]);
	}	
	printf("\b\b\b  \n");

}

void clear_stack(Stack& s) {

	free(s.elements);		

}
