
#include "main.h"

static void	checkOutOfBounds( Snake &snake )
{
	if (snake.getSnake().at(0).x < 0 || snake.getSnake().at(0).x >= 8)
		snake.getRunning().store(false);
	else if (snake.getSnake().at(0).y < 0 || snake.getSnake().at(0).y >= 8)
		snake.getRunning().store(false);
}

static void	checkDeath( Snake &snake )
{
	std::deque< Coord >::iterator it = snake.getSnake().begin(); 
	for (it++; it != snake.getSnake().end(); it++)
	{
		if (it->x == snake.getSnake().at(0).x && it->y == snake.getSnake().at(0).y)
		{
			snake.getRunning().store(false);
			return ;
		}
	}
}

void	gameRules( Snake &snake )
{
	Coord last {	snake.getSnake().end()->x,
					snake.getSnake().end()->y	};

	checkOutOfBounds(snake);
	checkDeath(snake);
	if (snake.getSnake().at(0).x == snake.getFood().load().x \
		&& snake.getSnake().at(0).y == snake.getFood().load().y)
	{
			
		snake.getSnake().push_back(last);
		if (!snake.addFood())
		{
			printw("\rYou won !\n\rPress any key to quit.");
			refresh();
			snake.getRunning().store(false);
			return ;
		}
	}
	if (snake.getRunning().load())
		printw("\rScore : %ld", snake.getSnake().size() - 2);
	else
		printw("\rGame over !\nFinal score : %ld.\n\rPress any key to quit.", snake.getSnake().size() - 2);
	refresh();
}

void	gameLoop( Snake &snake )
{
	while (snake.getRunning().load())
	{
		switch (snake.getDirection().load())
		{
		case 'u':
			snake.goNext();
			snake.getSnake().at(0).x--;
			snake.getLastMove().store('u');
			gameRules(snake);
			break ;
		case 'd':
			snake.goNext();
			snake.getSnake().at(0).x++;
			snake.getLastMove().store('d');
			gameRules(snake);
			break ;
		case 'l':
			snake.goNext();
			snake.getSnake().at(0).y--;
			snake.getLastMove().store('l');
			gameRules(snake);
			break ;
		case 'r':
			snake.goNext();
			snake.getSnake().at(0).y++;
			snake.getLastMove().store('r');
			gameRules(snake);
			break ;
		}
		delay(200);
	}
}