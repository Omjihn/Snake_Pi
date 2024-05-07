
#include "main.h"

void	keyHook(Snake& snake)
{
	while (snake.getRunning().load())
	{
		int ch;
		ch = getch();
		switch (ch)
		{
			case KEY_UP:
				snake.up();
				break;
			case KEY_DOWN:
				snake.down();
				break;
			case KEY_LEFT:
				snake.left();
				break;
			case KEY_RIGHT:
				snake.right();
				break;
			case 'q':
				snake.getRunning().store(false);
				return ;
		}
		delay(1);
	}
}