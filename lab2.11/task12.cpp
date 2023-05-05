#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

void string_input(char* stringArr);
void check_string(char* stringArr, const char* vowels);

int main() {
	//system("chcp 1251");
	int countSymb;

	char stringArr[SIZE];
	//char vowels[] = "ÀÅ¨ÈÎÓÛİŞß";
	//const char* vowels = "АЕЁИОУЫЭЮЯ";
	char vowels[] = "AEIOYU";

	string_input(stringArr);
	check_string(stringArr, vowels);

}

void string_input(char* stringArr) {
	fgets(stringArr, SIZE, stdin);
}

void check_string(char* stringArr, const char* vowels) {
	for (int i = 0; i < 6; i++) {
			if (strchr(stringArr, vowels[i])) {
				printf("%c ", vowels[i]);
			}
		}
	printf("\n");
}
