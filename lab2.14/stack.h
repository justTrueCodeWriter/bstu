struct Element {
	int data = 0;
	Element* next;
};

struct Stack {

	Element* head=NULL;

};

void push(Stack& s, int d); 
int pull(Stack& s); 
void print_stack(Stack& s);
void clear_stack(Stack& s, int &length);
