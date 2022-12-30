#include "terminal.h"
#include "menu.h"

int main(int, char**) {
    SetDefaultSizeOfTerminal();
    ClearTerminal();
    Menu();
}
