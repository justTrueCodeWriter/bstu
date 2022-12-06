#include <stdio.h>

int main() {

	double noseLength = 10;
	int daysCounter = 0;

	while(noseLength < 45.0) {
		noseLength += noseLength * 1/20;
		daysCounter += 2;
		printf("Days = %d; Nose Length = %lf\n", daysCounter, noseLength);
	}

	printf("This will happen in %d days.", daysCounter);
}
