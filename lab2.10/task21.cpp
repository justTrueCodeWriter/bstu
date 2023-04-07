#include <stdio.h>

#define SIZE 100

void string_input(char *str1, char *str2);
int get_len(char *stringArr);
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

int get_len(char *stringArr) {

	int counter=0;
	while (stringArr[counter]!='\n')	
		counter++;
	return counter;

}

void delete_second_from_first(char *str1, char *str2, char *strChanged) {
	int len1 = get_len(str1);
	printf("%d\n", len1);
	int len2 = get_len(str2);
	printf("%d\n", len2);

	for (int i = 0; i<len1-len2-1; i++) {
		for (int j = 0; i<len2; j++) {
			if (str1[i+j]==str2[j])
				str1[i+j]=' ';
		}
	}

	int k = 0;
	for (; k<len1; k++) {
		if (str1[k]!=' ')
			strChanged[k] = str1[k];
	}
	strChanged[k] = '\0';

}
