
#pragma once

# include <wiringPi.h>
# include <stdio.h>
# include <wiringShift.h>
# include <stdlib.h>
# include <signal.h>
# include <iostream>
# include <deque>
# include <ncurses.h>
# include <unistd.h>
# include <iomanip>
# include <thread>
# include <atomic>
# include <ctime>
# include <cstdlib>
# include <random>
# include <algorithm>

# define	dataPin		0
# define	latchPin	2
# define	clockPin	3

# define GAME_WIDTH 8
# define GAME_HEIGHT 8

struct Coord
{
	int	x;
	int	y;

	bool operator==( const Coord& other )
	{
		return (x == other.x && y == other.y);
	}
};


class	Snake
{
	private:

		std::deque< Coord >		_snake;
		std::atomic< Coord >	_food;
		std::atomic< bool >						_running;
		

		std::atomic< char >	_lastMove;	// 'u' = UP   | 'd' = DOWN
		std::atomic< char >	_direction;	// 'l' = LEFT | 'r' = RIGHT


	public:

		Snake( void );
		~Snake();

		void	up( void );
		void	down( void );
		void	left( void );
		void	right ( void );

		bool	addFood( void );
		void	goNext( void );

		void shiftOut(int dPin, int cPin, int order, unsigned char val);

		void	display( void );

		std::atomic< bool >	&getRunning( void );
		std::atomic< char >	&getDirection( void );
		std::atomic< char >	&getLastMove( void );
		std::atomic< Coord >	&getFood( void );
		std::deque< Coord >	&getSnake( void );

};
