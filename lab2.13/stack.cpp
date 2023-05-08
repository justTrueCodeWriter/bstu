#include <stdio.h>
#include <malloc.h>

#include "stack.h"

//Stack s;

void init_stack(Stack& s, int l) {

	if ((s.elements=(int*)malloc(sizeof(int)*l))) {
		s.l = l;
	}
	else s.l = -1;
	s.top=-1;

}

void distruct(Stack& s) {

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

int pull(Stack& s) {

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
