/*1. Пусть для каждого студента в группе, состоящей из N человек,
заданы оценки по трем экзаменам. Определить количество
отличников и их процент от общего числа студентов.*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct marks_t {
	int subject1, subject2, subject3; 
};

void user_array_filler(marks_t *array, int amountOfElements); 

int array_saver_binary(marks_t *array, int amountOfElements, char *fileName);
int array_reader_binary(marks_t *array, char *fileName);

int array_reader_txt(marks_t *array, char *fileName);
int amount();
int	excelent_students_counter(marks_t *array, int amountOfElements);
int mark_check(int mark);

double excelent_students_percent(int excelent_students_count, int amountOfElements);

int main() {

	int userChoice, amountOfElements, excelentStudentsCount;
	char textFileName[]="src.txt", binFileName[]="src.txt", savedBinFileName[]="saved.bin";
	double excelentStudentsPercent;
	marks_t array[SIZE];	

// FILL MODE
	do {
		printf("Select the array fill mode:\nUser input(1)/Array from text file(2)/Array from binary file(3): "); 
		scanf("%d", &userChoice);
		switch (userChoice) {
			case 1: amountOfElements = amount(); // AMOUNT OF STUDENTS
					user_array_filler(array, amountOfElements);
					array_saver_binary(array, amountOfElements, savedBinFileName);
					break;

			case 2: amountOfElements = array_reader_txt(array, textFileName);	
					if (amountOfElements == 0)
						return 0;
					break;

			case 3: amountOfElements = array_reader_binary(array, binFileName);
					if (amountOfElements == 0)
						return 0;
					break;

			default: printf("Mode must satisfy (choice = 1 or choice = 2 or choice = 3)\n");
		}
	}while((userChoice != 1)&&(userChoice != 2) && (userChoice != 3));

	excelentStudentsCount = excelent_students_counter(array, amountOfElements);	
	excelentStudentsPercent = excelent_students_percent(excelentStudentsCount, amountOfElements);

	printf("Excelent students count = %d\nExcelent students percent = %.3lf\n", 
			excelentStudentsCount, excelentStudentsPercent);

	return 0;

}

// AMOUNT
int amount() {

	int amountOfElements;

	do {
		printf("Amount of students = ");	scanf("%d", &amountOfElements);

		if (amountOfElements <= 0)
			printf("Amount of students must satisfy (n>0)\n");
	}while(amountOfElements <= 0);

	return amountOfElements;
}

// FILLING FROM USER
void user_array_filler(marks_t *array, int amountOfElements) {
	
	int flag;
	do {
		flag = 0;
		for (int i = 0; i < amountOfElements; i++) {
			printf("student %d: ", i+1);
			scanf("%d %d %d", &array[i].subject1, &array[i].subject2, &array[i].subject3);

			if (mark_check(array[i].subject1)*mark_check(array[i].subject2)*mark_check(array[i].subject3) == 0) {
					printf("ERROR: INCORRECT INPUT\nMust satisfy (0 < ELEMENT <= 5)\n");
					flag = 1;
					break;
			}
		}
	}while(flag != 0);
	

}

// SAVING DATA TO BINARY
int array_saver_binary(marks_t *array, int amountOfElements, char *fileName) {

	FILE *ft;
	ft=fopen(fileName, "wb");

	if (ft == 0) {
		printf("ERROR: CANT'T FIND SOURCE FILE\n");
		return 0;
	}

	for (int i = 0; i < amountOfElements; i++)
			fprintf(ft, "%d %d %d\n", array[i].subject1, array[i].subject2, array[i].subject3);

	fclose(ft);
	return 0;

}

//FILLING FROM BINARY FILE
int array_reader_binary(marks_t *array, char *fileName) {
	int amountOfElements;

	FILE *ft;
	ft=fopen(fileName,"rb");	

	if (ft == 0) {
		printf("ERROR: CANT'T FIND SOURCE FILE\n");
		return 0;
	}


	fscanf(ft, "%d", &amountOfElements);

	if (amountOfElements <= 0){
			printf("Amount of students must satisfy (n>0)\n");
			return 0;
	}
		
	for (int i = 0; i < amountOfElements; i++) {
			fscanf(ft, "%d %d %d", &array[i].subject1, &array[i].subject2, &array[i].subject3);

			if ((mark_check(array[i].subject1) * mark_check(array[i].subject2) * mark_check(array[i].subject3))==0) {
				printf("ERROR: INCORRECT INPUT\nMust satisfy (0 < ELEMENT <= 5)\n");
				return 0;
			}

	}

	fclose(ft);

	return amountOfElements;
}


// FILLING FROM TEXT FILE
int array_reader_txt(marks_t *array, char *fileName) {

	int amountOfElements;

	FILE *ft;
	ft=fopen(fileName,"rt");	

	if (ft == 0) {
		printf("ERROR: CANT'T FIND SOURCE FILE\n");
		return 0;
	}


	fscanf(ft, "%d", &amountOfElements);

	if (amountOfElements <= 0){
			printf("Amount of students must satisfy (n>0)\n");
			return 0;
	}
		
	for (int i = 0; i < amountOfElements; i++) {
			fscanf(ft, "%d %d %d", &array[i].subject1, &array[i].subject2, &array[i].subject3);

			if ((mark_check(array[i].subject1) * mark_check(array[i].subject2) * mark_check(array[i].subject3))==0) {
				printf("ERROR: INCORRECT INPUT\nMust satisfy (0 < ELEMENT <= 5)\n");
				return 0;
			}

	}

	fclose(ft);

	return amountOfElements;
}

int mark_check(int mark) {

	if 	((mark < 1) || (mark > 5))
		return 0;

	return 1;

}

// EXCELENT STUDENTS COUNT
int excelent_students_counter(marks_t *array, int amountOfElements) {

	int result;

	result = 0;
	for (int i = 0; i < amountOfElements; i++) 
		if (array[i].subject1 * array[i].subject2 * array[i].subject3 == 125)	
			result++;

	return result;

}

double excelent_students_percent(int excelentStudentsCount, int amountOfElements) {

	double result;

	result = excelentStudentsCount * 100.0 / amountOfElements;

	return result;	

}
