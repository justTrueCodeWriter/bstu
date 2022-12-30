/*1. Пусть для каждого студента в группе, состоящей из N человек,
заданы оценки по трем экзаменам. Определить количество
отличников и их процент от общего числа студентов.*/
#include <stdio.h>
#include <cstdlib>
#define SIZE 100

struct marks_t {
	int object1, object2, object3; 
};

void user_array_filler(marks_t *array, int amountOfElements); 

int input_file(marks_t *array, char*);
int amount();
int	excelent_students_counter(marks_t *array, int amountOfElements);
int mark_check(int mark);

double excelent_students_percent(int excelent_students_count, int amountOfElements);

int main() {

	int userChoice, amountOfElements, excelentStudentsCount;
	double excelentStudentsPercent;
	char fileName[] = "src.txt";
	marks_t array[SIZE];	

// FILL MODE
	do {
		printf("Select the array fill mode:\nUser input(1)/Array from file(2): "); 
		scanf("%d", &userChoice);
		if ((userChoice != 1)&&(userChoice != 2))
			printf("Mode must satisfy (choice = 1 or choice = 2)\n");
	}while((userChoice != 1)&&(userChoice != 2));


// CHOICE
	if (userChoice == 1) {
		amountOfElements = amount(); // AMOUNT OF STUDENTS
		user_array_filler(array, amountOfElements);
	}
	else {
		amountOfElements = input_file(array, fileName);	
		if (amountOfElements == 0)
			return 0;
	}

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
			scanf("%d %d %d", &array[i].object1, &array[i].object2, &array[i].object3);

			if (mark_check(array[i].object1)*mark_check(array[i].object1)*mark_check(array[i].object1) == 0) {
					printf("ERROR: INCORRECT INPUT\nMust satisfy (0 < ELEMENT <= 5)\n");
					flag = 1;
					break;
			}
		}
	}while(flag != 0);
	

}

// FILLING FROM FILE
int input_file(marks_t *array, char fileName[]) {

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
			fscanf(ft, "%d %d %d", &array[i].object1, &array[i].object2, &array[i].object3);

			if ((mark_check(array[i].object1) * mark_check(array[i].object2) * mark_check(array[i].object3))==0) {
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
		if ((array[i].object1 == 5) && (array[i].object2 == 5) && (array[i].object3 == 5))	
			result++;

	return result;

}

double excelent_students_percent(int excelentStudentsCount, int amountOfElements) {

	double result;

	result = excelentStudentsCount * 100.0 / amountOfElements;

	return result;	

}
