#include "Header.h"
void ShowManager() {
    bool running = true;
    while (running) {
        system("cls");
        std::cout << "EduConfig by Matteo Jakob\n\n";
        std::cout << "\t\tSelect an option:\n\n";
        std::cout << "\t\t[0] Show person list [1] Show room list [2] Create Curriculum (Coming Soon) [3] quit\n";

        bool selectedMethod = false;
        while (!selectedMethod)
        {
            int input = std::getchar();

            switch (input) {
            case '0':
                selectedMethod = true;
                ShowPersonList();
                break;
            case '1':
                selectedMethod = true;
                ShowRoomList();
                break;
            case '3':
                selectedMethod = true;
                running = false;
                break;
            default:
                CoutError("Invalid Input");
                break;
            }

        }
    }
	
}

void CoutError(const char* message) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);
    std::cout << "[!] " << message << std::endl;
    SetConsoleTextAttribute(hConsole, 0);
}

void loadPersonList() {

}