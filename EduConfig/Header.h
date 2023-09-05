#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <cstdlib> 
#include <vector>
#include <fstream>

struct BDATE {
	int day;
	int month;
	int year;
};

void SetConsoleSize();
void Intro();
void CoutError(const char* message); 
void ShowManager();

void ShowPersonList();
void ShowRoomList();

void AddPerson();
void EditPerson();
void RemovePerson();


class Person {
public:
	int id;
	const char* name;
	const char* surname;
    BDATE birthdate;
	const char* occupation;
	const std::vector<const char*>& subjects;

	Person(const char* n, const char* s, const BDATE& b, const char* o, const std::vector<const char*>& subs)
		: name(n), surname(s), birthdate(b), occupation(o), subjects(subs) {
		id = generateNextID();
	}
private:
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
};

std::vector<Person> personList;
