#include "Header.h"

void AddPerson() {
	std::cout << "Enter name: ";
	std::string name;
	std::cin >> name;
	Person person(name, "Doe", { 1, 1, 2000 }, "Teacher", { "Math", "Science" }, "");
	personList.push_back(person);
}
void EditPerson() {
	std::cout << "[!]\t" << "coming soon..." << std::endl;
}
void RemovePerson() {
	std::cout << "[!]\t" << "coming soon..." << std::endl;
}