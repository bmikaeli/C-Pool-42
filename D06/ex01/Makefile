NAME = ex01
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
FLAG = -Wall -Werror -Wextra
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
