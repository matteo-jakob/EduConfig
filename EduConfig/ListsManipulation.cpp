#include "Header.h"

void AddPerson() {
	std::cout << "\nEnter name: ";
	std::string name;
	std::cin >> name;
	std::cin.ignore(10000, '\n');

	std::cout << "\nEnter Surname: ";
	std::string surname;
	std::cin >> surname;
	std::cin.ignore(10000, '\n');

	std::cout << "\nEnter Birthdate (day): ";
	std::string birthdateDay;
	std::cin >> birthdateDay;
	std::cin.ignore(10000, '\n');

	std::cout << "\nEnter Birthdate (month): ";
	std::string birthdateMonth;
	std::cin >> birthdateMonth;
	std::cin.ignore(10000, '\n');

	std::cout << "\nEnter Birthdate (year): ";
	std::string birthdateYear;
	std::cin >> birthdateYear;
	std::cin.ignore(10000, '\n');

	std::cout << "\nEnter Role: ";
	std::string role;
	std::cin >> role;
	std::cin.ignore(10000, '\n');

	std::vector<std::string> subjects;
	bool receivedAllSubjects = false;
	while (!receivedAllSubjects) {
		std::cout << "\nEnter Subject: ";
		std::string subject;
		std::cin >> subject;
		std::cin.ignore(10000, '\n');

		subjects.push_back(subject);

		std::cout << "\nWould you like to add more? [y|n]";
		std::string input;
		std::cin >> input;
		std::cin.ignore(10000, '\n');

		if (input == "n")
			receivedAllSubjects = true;
	}
	std::cout << "\nEnter description: ";
	std::string description;
	std::getline(std::cin, description);
	std::cin.ignore(10000, '\n');

	Person newPerson(name, surname, { stoi(birthdateDay), stoi(birthdateMonth), stoi(birthdateYear) }, role, subjects, description);
	personList.push_back(newPerson);

	std::cout << "Successfully added " << name << " " << surname << " to list." << std::endl;
}
void EditPerson() {
	std::cout << "Enter the ID to edit: ";
	int targetID;
	std::cin >> targetID;

	for (Person& person : personList) {
		if (person.GetId() == targetID) {
			PersonData currentData = person.GetData();
			std::cout << "Current Information for ID " << targetID << ": ";
			std::cout << "\tName: " << currentData.name; 
			std::cout << "\tSurname: " << currentData.surname;

			std::cout << "Enter new information (or leave blank to keep unchanged):" << std::endl;

			std::string newName;
			std::cout << "New Name: ";
			std::cin >> newName;
			if (newName == "")
				newName = currentData.name;

			std::string newSurname;
			std::cout << "New Surname: ";
			std::cin >> newSurname;
			if (newSurname == "")
				newSurname = currentData.surname;

			std::cout << "setting data...";
			person.SetData(newName, newSurname, currentData.birthdate, currentData.occupation, currentData.subjects, currentData.description);
		}
		std::cout << "Person with ID " << targetID << " not found." << std::endl;
	}
}
void RemovePerson() {
	std::cout << "Enter the ID or unique identifier of the person you want to remove: ";
	int targetID; 
	std::cin >> targetID;

	for (auto i = personList.begin(); i != personList.end(); ++i) {
		if (i->GetId() == targetID) {
			i = personList.erase(i);
			std::cout << "Person with ID " << targetID << " has been removed." << std::endl;
			return;
		}
	}

	std::cout << "Person with ID " << targetID << " not found." << std::endl;

}
void AddRoom() {
	std::cout << "\nEnter room name: ";
	std::string name;
	std::cin >> name;

	std::cout << "\nEnter capacity: ";
	int cap;
	std::cin >> cap;

	Room room(name, cap);
	rooms.push_back(room);
	std::cout << "Room added successfully!" << std::endl;
}