#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void string_input(char* stringArr);
int check_string(char* stringArr, const char* vowels);

int main() {
	system("chcp 1251");
	int countSymb;

	char stringArr[SIZE];
	//char vowels[] = "ÀÅ¨ÈÎÓÛİŞß";
	const char* vowels = "АЕЁИОУЫЭЮЯ";
	//char vowels[] = "AEIOYU";

	string_input(stringArr);
	countSymb = check_string(stringArr, vowels);

	printf("count = %d\n", countSymb);
}

void string_input(char* stringArr) {
	fgets(stringArr, SIZE, stdin);
}

int check_string(char* stringArr, const char* vowels) {
	int counter = 0;
	for (int j = 0; stringArr[j] != '\n'; j++) {
		 for (int i = 0; i < 10; i++) {
			//printf("%i %i\n", stringArr[j], vowels[i]);
			if (stringArr[j] == vowels[i]) {
				printf("%c ", stringArr[j]);
				counter++;
			}
		}
	}
	printf("\n");
	return counter;
}
