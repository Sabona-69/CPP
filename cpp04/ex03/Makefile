
NAME	= inteface

RM		= rm -f

SRC		=  AMateria.cpp Ice.cpp Cure.cpp ICharacter.cpp IMateriaSource.cpp main.cpp \

CFLAGS	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address

OBJ		= $(SRC:.cpp=.o)

CC		= c++

INCLUDE = AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp IMateriaSource.hpp

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
