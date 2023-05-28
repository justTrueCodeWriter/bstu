#include <stdio.h>
#include "ring_list.h"

void task(RingList& ring);

void fill_ring_by_task(RingList& ring);

int main() {

	RingList ringField;

	int userChoice = 0;

	while (true) {
		do {	
			printf("Mode:\nPush next(1)\nPush prev(2)\nPull(3)\nPrint ring(4)\nGo next(5)\nGo prev(6)\ntask(7)\nExit(8)\n> "); scanf("%d", &userChoice);
			switch (userChoice) {
				case 1: {
							int d;
							scanf("%d", &d);
							push_next(ringField, d);
						} break;
				case 2: {
							int d;
							scanf("%d", &d);
							push_prev(ringField, d); 
						}break;
				case 3:	pull(ringField); break; 
				case 4: print_ring(ringField); break;
				case 5: go_next(ringField); break;
				case 6: go_prev(ringField); break;
				case 7: task(ringField); break;
				case 8: clear_ring(ringField); return 0; break;
				default: printf("Incorrect choice!\n");
			}
		}while((userChoice>=1)||(userChoice<=8));
	}


}

void fill_ring_by_task(RingList& ring, int N) {

	int i = 1;
	push_prev(ring, i);
	for (Element * cur = ring.current; i-1 < N; cur = cur->next) {
		i++;
		push_prev(ring, i);
	}

}

void task(RingList& ring) {

	int N, k;	

	printf("N = "); scanf("%d", &N);
	printf("k = "); scanf("%d", &k);

	int arr[N];

	fill_ring_by_task(ring, N);

	print_ring(ring);

	int i = 0, j = 0, step = 0;
	for (Element *cur = ring.current->next; i < N; cur = cur->next) {
		if (step == k) {
			step = 0;
			//arr[j] = cur->data;
			arr[j] = pull(ring);
			j++;
		}	
		i++;	
		step++;
	}
	
	printf("Deleted: ");
	for (int l = 0; l < j; l++) {
		printf("%d ", arr[l]);
	}
	printf("\n");

	print_ring(ring);

	clear_ring(ring);

}
