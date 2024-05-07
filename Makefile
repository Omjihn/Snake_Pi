
NAME = Snake

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -g -lwiringPi -lncurses

SRC_DIR = ./
SRC =		main.cpp \
			init.cpp \
			gameLoop.cpp \
			keyHook.cpp \
			Snake.cpp

OBJ_DIR = ./obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))

###
###			Just for visuals effects

BLUE = "\033[0;36m"
WHITE = "\033[0;37m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"

TOTAL = $(words $(SRC))
COUNT = 0

define colorecho
	@tput civis
	@echo -n $(1) "     ["
	@for i in `seq 1 $(TOTAL)`; do \
		echo -n "▓"; \
		sleep 0.05; \
	done
	echo -n "]"; echo " 100%";
	@tput cnorm
endef

###
###

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(call colorecho, $(GREEN)Compiling program :  )
	@$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME)
	@echo $(GREEN)[$(NAME)] Successfully compilated !$(WHITE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@echo -n "Compiling objects files: "
	@echo -n "["
	
	@for i in `seq 1 $(shell echo $$(($(COUNT) * $(TOTAL) / $(TOTAL))))`; do \
		echo -n "▓"; \
	done
	@for i in `seq 1 $$(($(TOTAL) - $(COUNT) * $(TOTAL) / $(TOTAL)))`; do \
		echo -n "-"; \
	done
	@echo -n "] $(shell echo $$(($(COUNT) * 100 / $(TOTAL))))%    "
	@$(CC) $(CPPFLAGS) -c $< -o $@
	@echo -n "\r"

regular:
	@$(CC) $(SRC_DIR)/$(SRC) $(CPPFLAGS) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo $(RED)Objects files deleted$(WHITE)

fclean: clean
	@rm -f $(NAME)
	@echo $(RED)Program deleted$(WHITE)

re: fclean all
