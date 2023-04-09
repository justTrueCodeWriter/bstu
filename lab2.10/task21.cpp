#include <stdio.h>

#define SIZE 100

void string_input(char *str1, char *str2);
int get_len(char *stringArr);
int delete_second_from_first(char *str1, char *str2);

int main() {

	char str1[SIZE];
	char str2[SIZE];

	int errorCheck;

	string_input(str1, str2);	

	errorCheck = delete_second_from_first(str1, str2);

	if (errorCheck==1) 
		printf("str2 not in the str1\n");
	
	else
		printf("Edited str: %s\n", str1);

	return 0;

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

int delete_second_from_first(char *str1, char *str2) {
	int len1 = get_len(str1);
	int len2 = get_len(str2);

	char tmpArr1[len2];
	char tmpArr2[len2];

	bool isInLine = false;

	int getPosition=0;

	for (int i = 0; i < len2; i++) {
		tmpArr2[i] = str2[i];
	}

	for (int i = 0; i<len1-len2+1; i++) {
		for (int j = 0; j<len2; j++) {
			tmpArr1[j]=str1[i+j];
		}
	
		if (tmpArr1==tmpArr2){
			isInLine = true;
			getPosition=i;
			break;
		}
	}

	if (isInLine == true)
		for (int k = 0; k<len2; k++) {
			str1[getPosition+k] = ' ';
	}
	else
		return 1;	

	return 0;

}
