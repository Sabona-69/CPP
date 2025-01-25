
NAME	= megaphone

RM		= rm -f

SRC		= megaphone.cpp \

CFLAGS	= -Wall -Wextra -Werror #-std=c++98

OBJ		= $(SRC:.c=.o)

CC		= c++

INCLUDE = .hpp

all		: $(NAME)
			
%.o		: %.cpp #$(INCLUDE)
			$(CC) $(CFLAGS) -c $<  -o $@
$(NAME)	: $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $@
clean	: 
			$(RM) $(OBJ)

fclean	: clean
			$(RM) $(NAME)

re		: fclean all
