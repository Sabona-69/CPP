
NAME	= Harl2.0

RM		= rm -f

SRC		= Harl.cpp main.cpp \

CFLAGS	= -Wall -Wextra -Werror -std=c++98

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
