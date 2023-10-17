#include "Header.h"

void ShowPersonList() {
    system("cls");
    LoadPersonList();

    std::cout << "[id]\tName\tSurname\tOccupation\tDescription\tBirthyear\tSubjects" << std::endl;
    for (int i = 0; i < personList.size(); ++i)
    {
        PersonData person = personList[i].GetData();
        std::cout << "[" << person.id << "]\t" << person.name << " " << person.surname << "\t" << person.occupation << "\t" << person.description << "\t" << person.birthdate.year << "\t";
        for (std::string subj : person.subjects) {
            std::cout << subj << ", ";
        }
        std::cout << std::endl;
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
            SavePersonList();
            std::cout << "Successfully updated list!\n";
            validInput = true;
            break;
        case 1:
            EditPerson();
            SavePersonList();
            std::cout << "Successfully updated list!\n";
            validInput = true;
            break;
        case 2:
            RemovePerson();
            std::cout << "saving...";
            SavePersonList();
            std::cout << "Successfully updated list!\n";
            validInput = true;
            break;
        case 3:
            // quit
            validInput = true;
            break;
        default:
            CoutError("Invalid Input\n"); 
            std::cin.clear();
            break;
        }

        std::cout << "\n\n\tpress any key to continue ..." << std::endl;
        _getch();
    }
}

void LoadPersonList() {
    personList.clear();
    std::string filename = "person_data.txt";
    bool continueCheck = true;

    std::ifstream inputFile("person_data.txt");
    // create file if it doesnt exist
    if (!inputFile) {
        std::ofstream cf("person_data.txt");
        cf.close();
        inputFile.open("person_data.txt");
    }

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        continueCheck = false;
    }

    if (continueCheck) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            int id;
            std::string name;
            std::string surname;
            BDATE birthdate;
            std::string day, month, year;
            std::string occupation;
            std::vector<std::string> subjects;
            std::string description;

            if (!(iss >> id)) {
                std::cerr << "Error reading id from line: " << line << std::endl;
                continue;
            }

            if (!(iss >> name >> surname)) {
                std::cerr << "Error reading name and surname from line: " << line << std::endl;
                continue;
            }

            if (!(iss >> birthdate.day >> birthdate.month >> birthdate.year)) {
                std::cerr << "Error reading birthdate from line: " << line << std::endl;
                continue;
            }

            if (!(iss >> occupation)) {
                std::cerr << "Error reading occupation from line: " << line << std::endl;
                continue;
            }

            std::string subjectsStr;
            if (!(iss >> std::ws >> subjectsStr)) {
                std::cerr << "Error reading subjects from line: " << line << std::endl;
                continue;
            }

            // Split subjects by commas
            std::istringstream subjectsIss(subjectsStr);
            subjects.clear();
            while (std::getline(subjectsIss, subjectsStr, ',')) {
                subjects.push_back(subjectsStr);
            }

            // Read the description
            if (!(std::getline(iss >> std::ws, description))) {
                std::cerr << "Error reading description from line: " << line << std::endl;
                continue;
            }

            Person person(name, surname, birthdate, occupation, subjects, description, id);
            personList.push_back(person);
        }

        inputFile.close();
    }
    else {
        std::cout << "Unable to open file." << std::endl;
    }
}

void SavePersonList() {
    std::ofstream outputFile("person_data.txt");
    if (!outputFile) {
        std::ofstream cf("person_data.txt");
        cf.close();
        outputFile.open("person_data.txt");
    }

    if (outputFile.is_open()) {
        outputFile.clear();
        for (Person& person : personList) {
            PersonData data = person.GetData();
            outputFile << data.id << " "
                << data.name << " "
                << data.surname << " "
                << data.birthdate.day << " "
                << data.birthdate.month << " "
                << data.birthdate.year << " "
                << data.occupation << " ";

            for (const std::string& subject : data.subjects) {
                outputFile << subject << ",";
            }

            outputFile << " " << data.description << "\n";
        }

        outputFile.close();
        std::cout << "Person list saved to file." << std::endl;


        std::ifstream filecontent("person_data.txt");
        if (filecontent.is_open()) {
            std::string content;
            filecontent >> content;
            std::cout << "This is the updated content of file: " << content << std::endl;
            filecontent.close();
        }
    }
    else {
        std::cout << "Unable to open file for saving." << std::endl;
    }
}

std::vector<Room> ReadRoomsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::ofstream createFile("rooms.txt");
        createFile.close();
        file.open("rooms.txt");
    }

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::string name;
            int capacity;
            std::istringstream iss(line);
            if (iss >> name >> capacity) {
                rooms.push_back(Room(name, capacity));
            }
        }
        file.close();
    }
    else {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
    }

    return rooms;
}

void ShowRoomList() {
    std::string filename = "rooms.txt";
    std::vector<Room> rooms = ReadRoomsFromFile(filename);

    if (!rooms.empty()) {
        std::cout << "List of Rooms from file:\n";
        for (const Room& room : rooms) {
            std::cout << "Room Name: " << room.name << "\tCapacity: " << room.capacity << std::endl;
        }
    }
    else {
        std::cout << "No rooms found in the file." << std::endl;
    }


    std::cout << "List of Rooms locally:\n";
    for (Room room : rooms) {
        std::cout << room.name << "\t Capacity:" << room.capacity << std::endl;
    }

    std::cout << "Would you like to add a room? [y|n]" << std::endl;
    std::string res;
    std::cin >> res;

    if (res == "y") {
        AddRoom();
    }
}

