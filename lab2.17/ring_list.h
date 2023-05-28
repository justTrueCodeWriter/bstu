struct Element {

	int data;
	Element *next=nullptr, *prev=nullptr;

};

struct RingList {

	Element *current=nullptr;

};

void push_next(RingList& ring, int d);
void push_prev(RingList& ring, int d);

int pull(RingList& ring);

void go_next(RingList& ring);
void go_prev(RingList& ring);

void print_ring(RingList ring);
void clear_ring(RingList& ring);
