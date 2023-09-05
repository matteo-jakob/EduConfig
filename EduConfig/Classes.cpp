#include "Header.h"

class Person {
public:
	const char* name;
	const char* surname;
	DATE birthdate;
};

class Teacher : public Person {
public:
	const char* subject;
};

class Student : public Person {
public:
	int studentID;
};
