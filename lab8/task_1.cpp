#include <stdio.h>

/*21. �������� ���������, ������� ���������� ������������ ����
������ ����� �� ��������� ������������������. ���� ������
���������� �� ��� ���, ���� ������������ �� ������ 0.*/
int task_1() {

	int number = 0, composition = 1;

	do {
		printf("number="); scanf_s("%d", &number);

		if ((number % 2 == 0) && (number != 0))
			composition *= number;

	} while ((number != 0) && (number != 13));

	printf("%d\n", composition);

	return 0;

}