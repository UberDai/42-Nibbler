# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/11 01:49:54 by amaurer           #+#    #+#              #
#    Updated: 2015/07/30 05:14:14 by adebray          ###   ########.fr        #
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

export CPP		=	clang++
export CPPFLAGS	=	-Wall -Werror -Wextra -pedantic -g3 -std=c++11 -stdlib=libc++
LDFLAGS			=	-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
LDFLAGS			+=	-rpath lib2/SFML/lib -force_load lib3/glfw/src/libglfw3.a

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.$(FILE_EXT)=.o))

all: _depend $(BIN_NAME)
	@echo "\033[32m•\033[0m $(BIN_DIR)$(NAME) is ready."

_depend:
	./configure.sh
	$(MAKE) -C lib1
	$(MAKE) -C lib2
	$(MAKE) -C lib3

$(BIN_NAME): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CPP) $(LDFLAGS) -o $(BIN_NAME) $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.$(FILE_EXT)
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS)$(subst $() $(), -I, $(INC_DIR)) -o $@ -c $<

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

.PHONY: all re fclean clean $(BIN_NAME)
