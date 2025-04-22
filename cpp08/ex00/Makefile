NAME	= easy

RM		= rm -f

SRC		= main.cpp \
        
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 # -g3  -fsanitize=address

OBJ		= $(SRC:.cpp=.o)

CPP		= c++

INCLUDE = easyfind.hpp

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
