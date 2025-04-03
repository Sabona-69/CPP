
NAME	= multipleForms

RM		= rm -f

SRC		= AForm.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp main.cpp 

CFLAGS	= -Wall -Wextra -Werror -std=c++98 #-g3 # -fsanitize=address

OBJ		= $(SRC:.cpp=.o)

CC		= c++

INCLUDE = AForm.hpp Bureaucrat.hpp Form.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp 

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