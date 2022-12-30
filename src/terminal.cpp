#include <iostream>
#include <cstdlib>

char FullRectCharBytes[] = {'\xE2', '\x96', '\xAE'};

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