
#include "main.h"

void	resetDisplay( void )
{
	int x = 0x80;
	for(int i = 0; i < 8; i++)
	{
		digitalWrite(latchPin, LOW);
		shiftOut(dataPin, clockPin, MSBFIRST, 0);
		shiftOut(dataPin, clockPin, MSBFIRST, ~x);
		digitalWrite(latchPin, HIGH);
		x >>= 1;
		delay(1);
	}
}

int main(void)
{
	init();
	Snake snake;

	std::thread inputThread(keyHook, std::ref(snake));
	std::thread gameLoopThread(gameLoop, std::ref(snake));

	while (snake.getRunning().load())
	{
		snake.display();
		delay(1);
	}
	resetDisplay();
	gameLoopThread.join();
	inputThread.join();
	endwin();

	return (0);
}