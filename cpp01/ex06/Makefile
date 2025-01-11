#colors

RED := \033[0;31m
GREEN := \033[0;32m
RESET := \033[0m


NAME	= harlFilter

RM		= rm -f

SRC		= Harl.cpp main.cpp \

CFLAGS	= -Wall -Wextra -Werror #-std=c++98

OBJ		= $(SRC:.cpp=.o)

CC		= c++

INCLUDE = Harl.hpp

all		: $(NAME)
			
%.o		: %.cpp $(INCLUDE)
			$(CC) $(CFLAGS) -c $<  -o $@
$(NAME)	: $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $@
clean	: 
			$(RM) $(OBJ)

fclean	: clean
			$(RM) $(NAME)

re		: fclean all
