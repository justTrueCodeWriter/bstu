#include <stdio.h>

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

	if ((stringArr[0]=='k')||(stringArr[0]=='K'))
		counter++;

	for (int i = 0; stringArr[i]!='\0'; i++) {
		if (((stringArr[i]==' ')&&(stringArr[i+1]=='k'))||
				((stringArr[i]==' ')&&(stringArr[i+1]=='K')))
				
			counter++;

	}

	return counter;
}
