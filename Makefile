#______________________________________//_______________________________________
INCD_DIR=	-I ./include \
			-I ./classes
INCD	=	include.hpp \
			Point.hpp \
			Node.hpp \
			Tree.hpp

SRC_DIR	=	./source \
			./classes
SRC		=	main.cpp \
			Point.cpp \
			Node.cpp \
			Tree.cpp \
			handlerInputFile.cpp \
			teste.cpp

OBJ_DIR	=	./builds
OBJ	=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

#______________________________________//_______________________________________
vpath %.hpp $(INCD_DIR)
vpath %.cpp $(SRC_DIR)

NAME	=	quad-tree

CFLAGS	=	-Wall -Wextra -Werror -g3 #-fsanitize=address

SDLFLAGS=	`sdl2-config --libs --cflags` -lSDL2_image -lm

RM		=	rm -rf

CC		=	c++
#______________________________________//_______________________________________
all:			$(NAME)

#	$(CC) $(CFLAGS) $(SDLFLAGS) $(OBJ) $(INCD_DIR) -o $(NAME) -lSDL2
$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCD_DIR) -o $(NAME)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|           quad-tree Criado           |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(OBJ_DIR)/%.o:	%.cpp $(INCD)
	mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $(CFLAGS) $(INCD_DIR) $<
#	$(CC) -c -o $@ $(CFLAGS) $(SDLFLAGS) $(INCD_DIR) $<
#______________________________________//_______________________________________
clean:
	$(RM) $(OBJ_DIR)
	@echo "\033[1;31m"
	@echo "/ ************************************ \\"
	@echo "|        Arquivos .o Deletados         |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

fclean:		clean
	$(RM) $(NAME)
	@echo "\033[1;31m"
	@echo "/ ************************************ \\"
	@echo "|          quad-tree Deletado          |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"
#______________________________________//_______________________________________

re:			fclean all

git:
	@git add .
	@git status
	@git commit -m "$m"

.PHONY:		all clean fclean re git
