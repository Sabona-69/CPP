#colors

RED := \033[0;31m
GREEN := \033[0;32m
RESET := \033[0m


NAME	= PhoneBook

RM		= rm -f

SRC		= main.cpp Contact.cpp PhoneBook.cpp \

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address#-std=c++98

OBJ		= $(SRC:.cpp=.o)

CC		= g++

INCLUDE = Contact.hpp PhoneBook.hpp \

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
