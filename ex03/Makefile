CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXXFLAGS += -Wconversion -Wunreachable-code 
#CXXFLAGS += -fno-elide-constructors

# -O0: Disables optimization to make debugging easier..
CXXFLAGS += -g3 -O0

# Uncomment this line to turn off debug flags
# CXXFLAGS += -DNDEBUG

CXX = c++

NAME = beats_coffee_making
ARGS =
SRCS = main.cpp 
SRCS += Bureaucrat.cpp 
SRCS += AForm.cpp 
SRCS += ShrubberyCreationForm.cpp 
SRCS += RobotomyRequestForm.cpp
SRCS += PresidentialPardonForm.cpp
SRCS += Intern.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# This is to recompile the .o files if the makefile changes
%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *_shrubbery

re: fclean all

run: all
	@echo
	@PATH=".$${PATH:+:$${PATH}}" && $(NAME) $(ARGS)

valrun: all
	@echo
	@PATH=".$${PATH:+:$${PATH}}" && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes $(NAME) $(ARGS)


.PHONY: all clean fclean re run valrun