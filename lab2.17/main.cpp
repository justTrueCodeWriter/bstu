/*N ребят располагаются по кругу. Начав отсчет от первого,
удаляют каждого k-го, смыкая при этом круг. Определить порядок
удаления ребят из круга.*/

#include <stdio.h>
#include <malloc.h>
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

	int i = N;

	push_next(ring, i);
	for (Element * cur = ring.current; i-1 > 0; cur = cur->next) {
		i--;
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
	for (int i = 0; i < N; i++) {
		go_prev(ring);
		if (step == k) {
			step = 0;
			//arr[j] = cur->data;
			arr[j] = pull(ring);
			j++;
		}	
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

void task2(RingList& ring) {

	int k = 0;

	printf("k = "); scanf("%d", &k);

	int i = 1;
	for (Element * cur = ring.current->next; cur != ring.current; cur = cur->next, i++) {
	
		if (i == k) {
			Element * e = cur;
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			cur = cur->next;
			free(e);
			break;
		}
	
	}

	

		

}

// TODO: функция удаления катого от текущего
