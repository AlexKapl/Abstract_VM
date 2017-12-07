# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 10:34:18 by akaplyar          #+#    #+#              #
#    Updated: 2017/12/07 19:45:56 by akaplyar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @clang++
CFLAGS = -Wall -Wextra -Werror -std=c++11

HEADER = vm.h

SRC =	main.cpp OperandFactory.cpp Lexer.cpp Token.cpp Exceptions.cpp\
		Parser.cpp ErrorHandler.cpp Operand.cpp MutantStack.cpp

OBJ =	$(SRC:%.cpp=obj/%.o)

vpath %.cpp src
vpath %.hpp includes

NAME = avm

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@printf "\x1B[32m\0%s created\x1B[0m\0\n" $(NAME)

obj/%.o: %.cpp
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\x1B[32m\0Compile %s\x1B[0m\0\n" $<

tests:
	@mkdir -p "misc/output"
	@echo "\n\033[1;33m\033[4;33mLaunching unit tests for abstract VM...\n\033[0m"
	@i=1; for d in misc/tests/* ; do \
		echo "$$i - Running test file \"$$d\":" ; \
		ruby $$d ; \
		i=$$(($$i+1)) ; \
		echo "" ; \
	done
	@echo "\033[1;33m\033[4;33mDone.\n\033[0m"

clean:
	@rm -rf obj
	@rm -rf misc/output
	@printf "\x1B[31m\0%s objects cleared\x1B[0m\0\n" ${NAME}

fclean: clean
	@rm -rf $(NAME)
	@printf "\x1B[31m\0%s deleted\x1B[0m\0\n" ${NAME}

re: fclean all
