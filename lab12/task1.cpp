/*10. Каждый раз, когда Буратино солжет, его нос вырастает
на 1/20 от предыдущей длины. Мудрый сверчок предупредил, что
с носом длиной более 45 см его ждут большие неприятности.
Определить, через сколько дней это может произойти, если Буратино
лжет через день, а первоначально длина носа была 10 см.*/
#include <stdio.h>

int lie_days_counter(double noseLength, int daysCounter);

int main() {

	double noseLength = 10;
	int daysCounter = 0;

	daysCounter = lie_days_counter(noseLength, daysCounter);	

	printf("This will happen in %d days.", daysCounter);
}

int lie_days_counter(double noseLength, int daysCounter) {

	if (noseLength < 45.0) {
		noseLength += noseLength * 1/20;
		daysCounter += 2;
		
		return lie_days_counter(noseLength, daysCounter);
	}	

	return daysCounter;

}
