#pragma once

struct BDATE {
    int day;
    int month;
    int year;
};
struct PersonData {
    int id;
    std::string name;
    std::string surname;
    BDATE birthdate;
    std::string occupation;
    std::vector<std::string> subjects;
    std::string description;
};

class Person {
private:
    int id;
    std::string name;
    std::string surname;
    BDATE birthdate;
    std::string occupation;
    std::vector<std::string> subjects;
    std::string description;

    static int nextID;

    static int generateNextID() {
        int idFromFile = LastIDFromFile();
        int nextID = idFromFile + 1;
        SaveNextIDToFile(nextID);
        return nextID;
    }

    static int LastIDFromFile() {
        int lastID = 0;
        std::ifstream file("last_id.txt");
        if (file.is_open()) {
            file >> lastID;
            file.close();
        }
        return lastID;
    }

    static void SaveNextIDToFile(int nextID) {
        std::ofstream file("last_id.txt");
        if (file.is_open()) {
            file << nextID;
            file.close();
        }
    }

public:
    Person(std::string n, std::string s, const BDATE& b, std::string o, std::vector<std::string> subs, std::string d)
        : name(n), surname(s), birthdate(b), occupation(o), subjects(subs), description(d) {
        id = generateNextID();
    }

    PersonData GetData() {
        PersonData data;
        data.id = id;
        data.name = name;
        data.surname = surname;
        data.birthdate = birthdate;
        data.occupation = occupation;
        data.subjects = subjects;
        data.description = description;
        return data;
    }

    void SetData(std::string n, std::string s, const BDATE& b, std::string o, std::vector<std::string> subs, std::string d) {
        name = n;
        surname = s;
        birthdate = b;
        occupation = o;
        subjects = subs;
        description = d;
    }
};

