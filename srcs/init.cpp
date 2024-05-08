
#include "main.h"

void	init( void )
{
	wiringPiSetup();
	
	pinMode(dataPin, OUTPUT);
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);

	newterm(NULL, stdout, stdin);
	printw("%s\n", WELLCOME_MSG);
	refresh();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
}