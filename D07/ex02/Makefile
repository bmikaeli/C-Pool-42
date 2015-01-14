NAME = ex02
SRC = main.cpp
FLAG = -Wall -Wextra -Werror
all : $(NAME)
$(NAME) : $(OBJ)
	g++ $(FLAG) $(SRC) -o $(NAME)
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
