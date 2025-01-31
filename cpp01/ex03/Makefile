
NAME	= war

RM		= rm -f

SRC		= HumanA.cpp HumanB.cpp Weapon.cpp main.cpp \

CFLAGS	= -Wall -Wextra -Werror #-std=c++98

OBJ		= $(SRC:.cpp=.o)

CC		= c++

INCLUDE = HumanA.hpp HumanB.hpp Weapon.hpp

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
