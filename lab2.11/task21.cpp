#include <stdio.h>
#include <string.h>

#define SIZE 100

void string_input(char *str1, char *str2);
int delete_second_from_first(char *str1, char *str2, char *strEdited);

int main() {

	char str1[SIZE];
	char str2[SIZE];
	char strEdited[SIZE];

	int errorCheck;

	string_input(str1, str2);	


	errorCheck = delete_second_from_first(str1, str2, strEdited);

	if (errorCheck==1) 
		printf("str2 not in the str1\n");
	
	else
		printf("Edited str: %s\n", strEdited);

	return 0;

}

void string_input(char *str1, char *str2) {

	printf("str1 = ");
	fgets(str1, SIZE, stdin);	

	printf("str2 = ");
	fgets(str2, SIZE, stdin);

}

int delete_second_from_first(char *str1, char *str2, char *strEdited) {

	int len1 = strlen(str1);
	int len2 = strlen(str2)-1;

	char tmpStr2[len2];
	strncpy(tmpStr2, str2, len2);

	char *getPosition = strstr(str1, tmpStr2);
	
	int n = getPosition-str1;

	if (getPosition) {
		strncpy(strEdited, str1, n);
		getPosition += len2;
		strcat(strEdited, getPosition);
	}
		
	else
		return 1;	

	return 0;

}
