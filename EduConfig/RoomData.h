#pragma once
#include <sstream>


struct Room {
    std::string name;
    int capacity;

    Room(const std::string& n, int c) : name(n), capacity(c) {}
};


std::vector<Room> ReadRoomsFromFile(const std::string& filename);
void ShowRoomList();
void AddRoom();

extern std::vector<Room> rooms;
