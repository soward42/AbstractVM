##
## EPITECH PROJECT, 2018
## abstractTMP
## File description:
## Makefile
##

SRC	=	src/main.cpp			\
		src/IO/IO.cpp			\
		src/Chipset/Parser.cpp		\
		src/Cpu/Cpu.cpp			\
		src/Memory/Memory.cpp		\
		src/Cpu/Factory.cpp		\
		src/Cpu/Operand.cpp		\
		src/Exception.cpp		\
		src/Chipset/Chipset.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	abstractVM

INC	=	-Iincludes -Iincludes/operands

CC	=	g++

CXXFLAGS	=	-W -Werror -Wall -Wextra -std=c++14 $(INC)

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)


clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

tests_run:
		make -C ./tests/

tests_clean:
		make fclean -C ./tests/
		make testClean -C ./tests/

dbg:	CXXFLAGS+=-g
dbg:	re

.PHONY:	all clean fclean re dbg