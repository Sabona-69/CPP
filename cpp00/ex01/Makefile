#colors

RED := \033[0;31m
GREEN := \033[0;32m
RESET := \033[0m


NAME	= 

RM		= rm -f

SRC		= .cpp \

CFLAGS	= -Wall -Wextra -Werror #-std=c++98

OBJ		= $(SRC:.c=.o)

CC		= c++

INCLUDE = .hpp

all		: $(NAME)
			
%.o		: %.c $(INCLUDE)
			cc $(CFLAGS) -c $<  -o $@
$(NAME)	: $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $@
clean	: 
			$(RM) $(OBJ)

fclean	: clean
			$(RM) $(NAME)

re		: fclean all
