#include <stdio.h>

int main() {

	int arr[3] = {1, 2, 3}, x, y, i;

	i = 0;
	x = arr[i+1];
	y = arr[i];
	printf("x = %d\ny = %d", x, y);

	return 0;

}
