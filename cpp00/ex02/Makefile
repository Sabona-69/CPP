NAME	= Account

RM		= rm -f

SRC		= tests.cpp Account.cpp \

CFLAGS	= -Wall -Wextra -Werror

OBJ		= $(SRC:.cpp=.o)

CC		= c++

INCLUDE = Account.hpp \

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
