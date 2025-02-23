
NAME	= replace

RM		= rm -f

SRC		= main.cpp Replace.cpp\

CFLAGS	= -Wall -Wextra -Werror -std=c++98

OBJ		= $(SRC:.cpp=.o)

CC		= c++

INCLUDE = Replace.hpp

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
