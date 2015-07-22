# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/11 01:49:54 by amaurer           #+#    #+#              #
#    Updated: 2015/07/22 00:34:27 by amaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC_DIR		=	src/
OBJ_DIR		=	build/
INC_DIR		=	include
BIN_DIR		=	bin/
FILE_EXT	=	cpp

NAME		=	snake
BIN_NAME	=	$(BIN_DIR)$(NAME)
SRC_FILES	=	main.cpp \
				Snake.cpp \
				Level.cpp \
				Player.cpp \
				GraphicHandler.cpp \
				Util.cpp

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.$(FILE_EXT)=.o))

CC			=	clang++
CC_FLAGS	=	-Wall -Werror -Wextra -pedantic -g3 -std=c++11 -stdlib=libc++
CC_LIBS		=

all: $(BIN_NAME)
	@echo "\033[32m•\033[0m $(BIN_DIR)$(NAME) is ready."

$(BIN_NAME): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) -o $(BIN_NAME) $(CC_LIBS) $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.$(FILE_EXT)
	@mkdir -p $(@D)
	$(CC) $(CC_FLAGS)$(subst $() $(), -I, $(INC_DIR)) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_NAME)

re: fclean all

.PHONY: all re fclean clean