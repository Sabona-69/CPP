
NAME	= DiamondTrap

RM		= rm -f

SRC		= DiamondTrap.cpp FragTrap.cpp ClapTrap.cpp ScavTrap.cpp main.cpp \

CFLAGS	= -Wall -Wextra -Werror -std=c++98

OBJ		= $(SRC:.cpp=.o)

CC		= c++

INCLUDE = DiamondTrap.hpp FragTrap.hpp ClapTrap.hpp ScavTrap.hpp

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
