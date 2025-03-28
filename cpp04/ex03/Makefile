
NAME	= inteface

RM		= rm -f

SRC		=  AMateria.cpp Character.cpp Cure.cpp Ice.cpp main.cpp MateriaSource.cpp \

CFLAGS	= -Wall -Wextra -Werror -std=c++98 #-g3 # -fsanitize=address

OBJ		= $(SRC:.cpp=.o)

CC		= c++

INCLUDE = AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp

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
