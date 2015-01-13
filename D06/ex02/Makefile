NAME = ex02
SRC = main.cpp \
	BClass.cpp \
	AClass.cpp \
	CClass.cpp \
	baseClass.cpp
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
