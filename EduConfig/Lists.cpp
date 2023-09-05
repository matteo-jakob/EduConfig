#include "Header.h"

void ShowPersonList() {
    system("cls");
    std::vector<Person> personList;
    std::ifstream inputFile("person_data.txt");

    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            std::string name;
            std::string  surname;
            BDATE birthdate;
            std::string  occupation;
            std::vector<std::string> subjects;
            std::string  description;

            Person person(name, surname, birthdate, occupation, subjects, description);
            personList.push_back(person);
        }
        inputFile.close();
    }
    else {
        std::cout << "Unable to open file." << std::endl;
    }

    Person test("Max", "Mustermann", { 1, 1, 2000 }, "student", { "Math", "English", "Russian" }, "");
    personList.push_back(test);

    for (int i = 0; i < personList.size(); ++i)
    {
        PersonData person = personList[i].GetData();
        std::cout << "[" << person.id << "]\t" << person.name << " " << person.surname <<  "\t" << person.occupation << std::endl;
    }


    std::cout << "[0] Add Person [1] Edit Person [2] Remove Person [3] quit" << std::endl;
    bool validInput = false;
    while (!validInput) {
        int input;
        std::cin >> input;

        switch (input)
        {
        case 0:
            AddPerson();
            validInput = true;
            break;
        case 1:
            EditPerson();
            validInput = true;
            break;
        case 2:
            RemovePerson();
            validInput = true;
            break;
        case 3:
            // quit
            validInput = true;
            break;
        default:
            CoutError("Invalid Input");
            break;
        }
    }
}

void ShowRoomList() {
    system("cls");

    std::cout << "\t\t\t\t\tPress any key to continue..." << std::endl;
    _getch();
}