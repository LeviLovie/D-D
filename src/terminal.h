#ifndef terminal_h
#define terminal_h

void ClearTerminal();
void MoveCursorTo(short x, short y);
void SetDefaultSizeOfTerminal();
void Exit(short code);

extern char FullRectCharBytes[];

#endif