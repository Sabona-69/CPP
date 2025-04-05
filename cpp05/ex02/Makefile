
NAME	= multipleForms

RM		= rm -f

SRC		= AForm.cpp Bureaucrat.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp main.cpp\

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 # -g3  -fsanitize=address

OBJ		= $(SRC:.cpp=.o)

CXX		= c++

INCLUDE = AForm.hpp Bureaucrat.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp 

all		: $(NAME)
			
%.o		: %.cpp $(INCLUDE)
			$(CXX) $(CXXFLAGS) -c $<  -o $@
$(NAME)	: $(OBJ)
			$(CXX) $(CXXFLAGS) $(OBJ) -o $@
clean	: 
			$(RM) $(OBJ)

fclean	: clean
			$(RM) $(NAME) *_shrubbery

re		: fclean all

.PHONY: clean