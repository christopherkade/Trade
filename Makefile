##
## Makefile for Makefile in /home/kade_c/trade_test
## 
## Made by Christopher Kade
## Login   <kade_c@epitech.net>
## 
## Started on  Sun May  8 15:04:07 2016 Christopher Kade
## Last update Wed Jun  1 13:51:56 2016 Christopher Kade
##

RM 	= rm -f

NAME 	= trade

SRCS 	= src/main.cpp\
	src/trade.cpp\
	src/actions.cpp\
	src/calc.cpp\
	src/convert/floatToString.cpp\
	src/convert/intToString.cpp\
	src/convert/stringToFloat.cpp\
	src/convert/stringToInt.cpp

OBJS 	= $(SRCS:.cpp=.o)

CXX 	= g++ -std=c++11

CXXFLAGS += -W -Wall -I./include -Werror

all: $(NAME)
	@printf "\n \033[33m[Message]\033[39m Compilation done.\n\n"


$(NAME): $(OBJS)
	@$(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	@$(RM) $(OBJS)
	@printf " \033[31m[Deletion] \033[39m%s\n" $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@printf " \033[31m[Deletion] \033[39m%s\n" $(NAME)

re: fclean all

.PHONY: all clean fclean re
