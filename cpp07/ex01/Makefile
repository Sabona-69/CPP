NAME	= iter

RM		= rm -f

SRC		= main.cpp \
        
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 #-g  -fsanitize=address

OBJ		= $(SRC:.cpp=.o)

CPP		= c++

INCLUDE = iter.hpp

all		: $(NAME)
            
%.o		: %.cpp $(INCLUDE)
		$(CPP) $(CPPFLAGS) -c $<  -o $@

$(NAME)	: $(OBJ)
		$(CPP) $(CPPFLAGS) $(OBJ) -o $@

clean	: 
		$(RM) $(OBJ)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all

.PHONY: clean
