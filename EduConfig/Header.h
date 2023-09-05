#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <cstdlib> 
#include <vector>
#include <fstream>

#include "PersonData.h"

void SetConsoleSize();
void Intro();
void CoutError(const char* message); 
void ShowManager();

void ShowPersonList();
void ShowRoomList();

void AddPerson();
void EditPerson();
void RemovePerson();

extern std::vector<Person> personList;
