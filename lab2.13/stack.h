
struct Stack {

	int *elements;
	int l;
	int top;

};

void init_stack(Stack& s, int l);
void destruct(Stack& s);

int push(Stack& s, int d); 
int pull(Stack& s); 
void print_stack(Stack& s);
void clear_stack(Stack& s);
