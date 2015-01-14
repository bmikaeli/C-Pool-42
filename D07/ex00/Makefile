NAME = ex00
SRC = ex00.cpp
OBJ = $(SRC:.cpp=.o)
FLAG = -Wall -Wextra -Werror
all : $(NAME)
$(NAME) : $(OBJ)
	g++ $(FLAG) $(OBJ) -o $(NAME)
%.o: %.cpp
	g++ $(FLAG) -c $^
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
