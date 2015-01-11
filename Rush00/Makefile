NAME = ft_retro
SRC = main.cpp \
    AAlien.class.cpp\
    Aweapon.class.cpp \
    Bullet.Weapon.class.cpp\
    Stupid.Alien.class.cpp\
    User.class.cpp \
    RocketLauncher.Weapon.class.cpp \
    Laser.Weapon.class.cpp \
    WindowRetro.class.cpp
OBJ = $(SRC:.cpp=.o)
FLAG = -Wall -Werror -Wextra -lncurses
all : $(NAME)
$(NAME) : $(OBJ)
	g++ $(FLAG) $(OBJ) -o $(NAME)
%.o: %.cpp
	g++ -c $^
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all