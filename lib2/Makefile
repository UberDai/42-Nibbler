NAME		=	lib2.so
SRC			=	$(shell ls | grep ".cpp")
OBJ			=	$(subst .cpp,.o,$(SRC))

CPP			?=	clang++
CPPFLAGS	?=	-Wall -Wextra -Werror -std=c++11
CPPFLAGS	+=	-I../include -ISFML/include

LDFLAGS		=	-shared -fPIC
LDFLAGS		+=	-LSFML/lib
LDFLAGS		+=	-lsfml-audio
LDFLAGS		+=	-lsfml-graphics
LDFLAGS		+=	-lsfml-network
LDFLAGS		+=	-lsfml-window
LDFLAGS		+=	-lsfml-system

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(LDFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $<

re: fclean all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
