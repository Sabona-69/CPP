
NAME	= bureaucrat

RM		= rm -f

SRC		= Bureaucrat.cpp main.cpp \

CFLAGS	= -Wall -Wextra -Werror -std=c++98 ## -g3 # -fsanitize=address

OBJ		= $(SRC:.cpp=.o)

CC		= c++

INCLUDE = Bureaucrat.hpp

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
