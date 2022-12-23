#______________________________________//_______________________________________
INCD_DIR=	-I ./ \
			-I ./classes
INCD	=	include.hpp \
			Point.hpp \
			Node.hpp \
			Tree.hpp

SRC_DIR	=	./classes
SRC		=	Point.cpp \
			Node.cpp \
			Tree.cpp
MAIN_SRC	= $(SRC) main.cpp
TESTE_SRC	= $(SRC) mainTeste.cpp

OBJ_DIR	=	./builds
MAIN_OBJ	=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(MAIN_SRC))
TESTE_OBJ	=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(TESTE_SRC))

#______________________________________//_______________________________________
vpath %.hpp $(INCD_DIR)
vpath %.cpp $(SRC_DIR)

NAME	=	quad-tree
TESTE	=	teste

CFLAGS	=	-Wall -Wextra -Werror -g3 #-fsanitize=address

SDLFLAGS=	`sdl2-config --libs --cflags` -lSDL2_image -lm

RM		=	rm -rf

CC		=	c++
#______________________________________//_______________________________________
all:			$(NAME)

$(NAME):	$(MAIN_OBJ)
	$(CC) $(CFLAGS) $(SDLFLAGS) $(MAIN_OBJ) $(INCD_DIR) -o $(NAME) -lSDL2
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|           quad-tree Criado           |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(TESTE):	$(TESTE_OBJ)
	$(CC) $(CFLAGS) $(SDLFLAGS) $(TESTE_OBJ) $(INCD_DIR) -o $(TESTE) -lSDL2
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             teste Criado             |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"


$(OBJ_DIR)/%.o:	%.cpp $(INCD)
	mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $(CFLAGS) $(SDLFLAGS) $(INCD_DIR) $<
#______________________________________//_______________________________________
clean:
	$(RM) $(OBJ_DIR)
	@echo "\033[1;31m"
	@echo "/ ************************************ \\"
	@echo "|        Arquivos .o Deletados         |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

fclean:		clean
	$(RM) $(NAME) $(TESTE)
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
