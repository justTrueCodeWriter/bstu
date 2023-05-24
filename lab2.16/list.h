#define SURNAME_BUFFER 15

struct Student {

	char surname[SURNAME_BUFFER];
	char year;
	char group;
	char marks[5];
	Student *next;

};
