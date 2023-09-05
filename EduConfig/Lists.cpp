#include "Header.h"

void ShowPersonList() {
    system("cls");
    
    std::ifstream inputFile("person_data.txt");

    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            const char* name;
            const char* surname;
            BDATE birthdate;
            const char* occupation;
            std::vector<const char*> subjects; 

            Person person(name, surname, birthdate, occupation, subjects);
            personList.push_back(person);
        }
        inputFile.close();
    }
    else {
        std::cout << "Unable to open file." << std::endl;
    }

    for (int i = 0; i < personList.size(); ++i)
    {
        std::cout << personList[i].id << " " << personList[i].name << std::endl;
    }


    std::cout << "[0] Add Person [1] Edit Person [2] Remove Person [3] quit" << std::endl;
    bool validInput = false;
    while (!validInput) {
        int input = std::getchar();

        switch (input)
        {
        case '0':
            AddPerson();
            validInput = true;
            break;
        case '1':
            EditPerson();
            validInput = true;
            break;
        case '2':
            RemovePerson();
            validInput = true;
            break;
        case '3':
            RemovePerson();
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