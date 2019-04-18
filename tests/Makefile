##
## EPITECH PROJECT, 2018
## autoCompletion
## File description:
## Unit test Makefile
##

SRC		=	../src/Chipset/Parser.cpp		\
			../src/Cpu/Operand.cpp			\
			../src/Memory/Memory.cpp		\
			../src/Cpu/Factory.cpp			\
			../src/Exception.cpp			\
			../src/IO/IO.cpp			\
			../src/Cpu/Cpu.cpp

SRC_UT		=	UT_src/UT_parser.cpp		\
			UT_src/UT_cpu.cpp

OBJ		=	$(SRC:%.cpp=%.o) $(SRC_UT:%.cpp=%.o)

CCTMP		=	$(SRC:%.cpp=%.gcno) $(SRC:%.cpp=%.gcda) $(SRC_UT:%.cpp=%.gcno) $(SRC_UT:%.cpp=%.gcda)

CXXFLAGS	=	-W -Wall -Wextra -std=c++14			\
			--coverage -fprofile-arcs -ftest-coverage	\
			-I../includes

LDFLAGS		=	-lcriterion -lgcov

CC 		=	g++

NAME		=	autocomp_unit_tests

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(SRC) $(SRC_UT) $(LDFLAGS) $(CXXFLAGS)

clean:
		@rm -f $(OBJ)
		@rm -f $(CCTMP)

fclean:		clean
		@rm -f $(NAME)

testClean:
		@rm -f *.g*

re:		testClean fclean all
.PHONY: all clean fclean re
