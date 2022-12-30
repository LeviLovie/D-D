#include <iostream>
#include <cstdlib>
#include <string>

char FullRectCharBytes[] = {'\xE2', '\x96', '\xAE'};
std::string StringTrash;
int IntTrash;

void ClearTerminal() {
    std::wcout << "\033c" << std::endl;
}

void MoveCursorTo(short x, short y) {
    std::wcout << "\033[" << y << ";" << x << "H" << std::endl;
}

void SetDefaultSizeOfTerminal() {
    std::cout << "\033[8;28;120t";
}

void Exit(short code) {
    std::exit(code);
}

void Cout(std::string str) {
    std::cout << str;
}

void CoutEndl(std::string str) {
    std::cout << str << std::endl;
}

void DrawInTerm(std::string str) {
    MoveCursorTo(0, 26);
    for (short i = 0; i < 120; i++) {
        std::cout.write(FullRectCharBytes, 3);
    }
    MoveCursorTo(0, 27);
    std::cout << str;
    MoveCursorTo(0, 28);
    std::wcout << ">";
}

void ClearRAM() {
    StringTrash = "";
    IntTrash = 0;
    system("sync");
}