#include <stdio.h>

#define SIZE 100

void string_input(char *str1, char *str2);
void delete_second_from_first(char *str1, char *str2, char *strChanged);

int main() {

	char str1[SIZE];
	char str2[SIZE];
	char strChanged[SIZE];

	string_input(str1, str2);	
	delete_second_from_first(str1, str2, strChanged);
	
	printf("%s\n%s\n%s\n", str1, str2, strChanged);

}

void string_input(char *str1, char *str2) {

	printf("str1 = ");
	fgets(str1, SIZE, stdin);	

	printf("str2 = ");
	fgets(str2, SIZE, stdin);

}

void delete_second_from_first(char *str1, char *str2, char *strChanged) {
	
	for (int i = 0; str1[i]!='\0'; i++) {
		for (int j = 0; str2[j]!='\0'; j++) {
			if (str1[i+j]==str2[j])
				str1[i+j]=' ';
		}
	}
	int k = 0;
	for (; str1[k]!='\0'; k++) {
		if (str1[k]!=' ')
			strChanged[k] = str1[k];
	}
	strChanged[k] = '\0';

}
