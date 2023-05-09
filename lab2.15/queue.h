struct Element {
	int data;
	Element* next;
};

struct Queue {

	Element* head=NULL, *tail=NULL;

};

void push(Queue& q, int d); 
int pull(Queue& q); 
void print_queue(Queue& q);
void clear_queue(Queue& q, int &length);
