#include "Header.h"

void AddPerson() {
	std::cout << "Enter name: ";
	std::string name;
	std::getline(std::cin, name);
	const char* nameCStr = name.c_str();
	Person person(nameCStr, "Doe", { 1, 1, 2000 }, "Teacher", { "Math, Science" });
}
void EditPerson() {

}
void RemovePerson() {

}