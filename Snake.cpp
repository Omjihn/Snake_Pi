
#include "Snake.hpp"

Snake::Snake( void )
{
	_snake.push_front(Coord{1, 0});
	_snake.push_back(Coord{0, 0});
	_running.store(true);

	_lastMove.store('d');
	_direction.store('d');
	addFood();
}

Snake::~Snake( )
{

}

void	Snake::display( void )
{
	unsigned char leds[8] = {0};

	for (const auto &segment : getSnake())
		leds[segment.x] += 1 << segment.y;
	leds[ _food.load().x] += 1 << _food.load().y;

	int x = 0x80;
	for(int i = 0; i < 8; i++)
	{
		digitalWrite(latchPin, LOW);
		shiftOut(dataPin, clockPin, MSBFIRST, leds[i]);
		shiftOut(dataPin, clockPin, MSBFIRST, ~x);
		digitalWrite(latchPin, HIGH);
		x >>= 1;
		delay(1);
	}
}

void	Snake::shiftOut(int dPin, int cPin, int bitOrder, unsigned char val)
{
	int i;
	for(i = 0; i < 8; i++)
	{
		digitalWrite(cPin, LOW);
		if(bitOrder == LSBFIRST)
		{
			digitalWrite(dPin,( (0x01 & (val >> i)) == 0x01) ? HIGH : LOW);
			delayMicroseconds(10);
	}
		else
		{
			digitalWrite(dPin,( ( 0x80 & (val << i)) == 0x80) ? HIGH : LOW);
			delayMicroseconds(10);
	}
		digitalWrite(cPin, HIGH);
		delayMicroseconds(10);
	}
}

bool	Snake::addFood( void )
{
	if (_snake.size() == (8 * 8))
		return (false);
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> disX(0, GAME_WIDTH - 1);
	std::uniform_int_distribution<> disY(0, GAME_HEIGHT - 1);

	for (int i = 0; i < GAME_HEIGHT * GAME_WIDTH; ++i)
	{
		Coord food;
		food.x = disX(gen);
		food.y = disY(gen);
		
		if (std::find(_snake.begin(), _snake.end(), food) == _snake.end())
		{
			_food.store(food);
			return (true);
		}
	}
	return (false);
}

void Snake::goNext( void )
{
	if (_snake.size() < 2)
		return;
	for (auto it = _snake.end(); it != _snake.begin(); it--)
		*it = *(it - 1);
}

void	Snake::up( void )
{
	if (_lastMove.load() == 'd')
		return ;
	_direction.store('u');
}

void	Snake::down( void )
{
	if (_lastMove.load() == 'u')
		return ;
	_direction.store('d');
}

void	Snake::left( void )
{
	if (_lastMove.load() == 'r')
		return ;
	_direction.store('l');
}

void	Snake::right( void )
{
	if (_lastMove.load() == 'l')
		return ;
	_direction.store('r');
}

std::atomic<bool>	&Snake::getRunning( void )
{
	return (_running);
}

std::atomic< char >	&Snake::getDirection( void )
{
	return (_direction);
}

std::atomic< char >	&Snake::getLastMove( void )
{
	return (_lastMove);
}

std::deque< Coord >	&Snake::getSnake( void )
{
	return (_snake);
}

std::atomic< Coord >	&Snake::getFood( void )
{
	return (_food);
}