#include <stdio.h>
#include <string.h>

#define SIZE 100

void string_input(char *stringArr);
int check_string(char *stringArr);

int main() {
	int countK, stringSize;

	char stringArr[SIZE];	

	string_input(stringArr);
	countK = check_string(stringArr);

	printf("count = %d\n", countK);

}

void string_input(char *stringArr) {

	fgets(stringArr, SIZE, stdin);	

}

int check_string(char *stringArr) {
	int counter = 0;
	const char* pattern = "k k";
	if (!strncasecmp(stringArr, pattern, 1))
		counter++;

	for (int i = 0; stringArr[i]!='\0'; i++) {
		if (!strncasecmp(&stringArr[i], &pattern[1], 2))
			counter++;

	}

	return counter;
}
