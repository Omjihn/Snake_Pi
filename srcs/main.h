
#pragma once

# include "Snake.hpp"

# define WELLCOME_MSG "###########################################\n###################SNAKE###################\n###########################################"

void	init( void );
void	resetDisplay( void );
void	gameLoop( Snake &snake );
bool	addFood( Snake& snake );
void	keyHook( Snake& snake );