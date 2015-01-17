NAME = ft_gkrellm
SRC = main.cpp \
    IMonitorModule.cpp \
    IMonitorDisplay.cpp \
    HostnameModule.cpp \
    OsInfoModule.cpp \
    DateModule.cpp \
    CliMonitor.cpp \
    GuiMonitor.cpp
OBJ = $(SRC:.cpp=.o)
FLAG = -Wall -Werror -Wextra -lncurses -g
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
