#include <stdio.h>
#define SIZE 100
void string_input(char *stringArr);
int check_string(char *stringArr, const char *vowels);
int main() {
	int countSymb;

	char stringArr[SIZE];	
	char vowels[] = "АЕЁИОУЫЭЮЯ";
	//char vowels[] = "AEIOYU";

	string_input(stringArr);
	countSymb = check_string(stringArr, vowels);

	printf("count = %d\n", countSymb);
}

void string_input(char *stringArr) {
	fgets(stringArr, SIZE, stdin);	
}

int check_string(char *stringArr, const char *vowels) {
	int counter = 0;
	for (int i = 0; i < 21; i++) {
		for (int j = 0; stringArr[j]!='\n'; j++) {
			printf("%c %c\n", stringArr[j], vowels[i]);
			if (stringArr[j]==vowels[i]) {
				counter++;
			}
		}
	}
	return counter;
}
