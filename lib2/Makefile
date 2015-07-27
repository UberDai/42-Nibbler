NAME		=	lib2.so
SRC			=	$(shell ls | grep ".cpp")
OBJ			=	$(subst .cpp,.o,$(SRC))

CXX			?=	clang++
CXXFLAGS	?=	-Wall -Wextra -Werror -std=c++11
CXXFLAGS	+=	-I../include -ISFML/include

LDFLAGS		=	-shared -fPIC
LDFLAGS		+=	-LSFML/lib
LDFLAGS		+=	-lsfml-audio
LDFLAGS		+=	-lsfml-graphics
LDFLAGS		+=	-lsfml-network
LDFLAGS		+=	-lsfml-window
LDFLAGS		+=	-lsfml-system

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(LDFLAGS) -o $(NAME) $(OBJ)

re: fclean all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
