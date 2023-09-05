#include "Header.h"

int main()
{
    SetConsoleSize();
    Intro();
    ShowManager();
}

void Intro() {
    std::cout << "\t\t\t\t\tEduConfig\n\t\t\t\t\tVersion 0.1 by Matteo Jakob\n\n\n";

    // Ascii source: https://www.asciiart.eu/art-and-design/egyptian
    const char* logoArt = R"V0G0N(
                                                        /^\
                                     L L               /   \               L L
                                  __/|/|_             /  .  \             _|\|\__
                                 /_| [_[_\           /     .-\           /_]_] |_\
                                /__\  __`-\_____    /    .    \    _____/-`__  /__\
                               /___] /=@>  _   {>  /-.         \  <}   _  <@=\ [___\
                              /____/     /` `--/  /      .      \  \--` `\     \____\
                             /____/  \____/`-._> /               \ <_.-`\____/  \____\
                            /____/    /__/      /-._     .   _.-  \      \__\    \____\
                           /____/    /__/      /         .         \      \__\    \____\
                          |____/_  _/__/      /          .          \      \__\_  _\____|
                           \__/_ ``_|_/      /      -._  .        _.-\      \_|_`` _\___/
                             /__`-`__\      <_         `-;        NDT_>      /__`-`__\
                                `-`           `-._       ;       _.-`           `-`
                                                  `-._   ;   _.-`
                                                      `-._.-`
    )V0G0N";

    std::cout << logoArt << std::endl;
    std::cout << "\n\n\n\t\t\t\t\tPress any key to continue..." << std::endl;
    _getch();
}

void SetConsoleSize() {
    // This function was completed with the help of ChatGPT

    HWND console = GetConsoleWindow();
    COORD size = { 100, 30 }; 
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), size);
    RECT r;
    GetClientRect(console, &r);
    MoveWindow(console, r.left, r.top, 1280, 720, TRUE);
}