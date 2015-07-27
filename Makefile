# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/11 01:49:54 by amaurer           #+#    #+#              #
#    Updated: 2015/07/28 00:28:29 by adebray          ###   ########.fr        #
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
				GraphicsHandler.cpp \
				Util.cpp

export CXX		=	clang++
export CXXFLAGS	=	-Wall -Werror -Wextra -pedantic -g3 -std=c++11 -stdlib=libc++
LDFLAGS			+=	-rpath lib2/SFML-2.2/lib

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.$(FILE_EXT)=.o))

_depend:
	$(MAKE) -C lib1
	$(MAKE) -C lib2
	$(MAKE) -C lib3

all: _depend $(BIN_NAME)
	@echo "\033[32m•\033[0m $(BIN_DIR)$(NAME) is ready."

$(BIN_NAME): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(LDFLAGS) -o $(BIN_NAME) $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.$(FILE_EXT)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS)$(subst $() $(), -I, $(INC_DIR)) -o $@ -c $<

clean:
	$(MAKE) -C lib1 clean
	$(MAKE) -C lib2 clean
	$(MAKE) -C lib3 clean
	rm -rf $(OBJ_DIR)

fclean:
	$(MAKE) -C lib1 fclean
	$(MAKE) -C lib2 fclean
	$(MAKE) -C lib3 fclean
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_NAME)

re: fclean all

.PHONY: all re fclean clean
