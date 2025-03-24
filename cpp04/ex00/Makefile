
NAME	= DiamondTrap

RM		= rm -f

SRC		= Animal.cpp Dog.cpp Cat.cpp main.cpp \

CFLAGS	= -Wall -Wextra -Werror -std=c++98 -Wno-shadow

OBJ		= $(SRC:.cpp=.o)

CC		= c++

INCLUDE = Animal.hpp Dog.hpp Cat.hpp

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
