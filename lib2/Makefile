NAME		=	lib2.so
SRC			=	$(shell ls | grep ".cpp")
OBJ			=	$(subst .cpp,.o,$(SRC))

CXX			?=	clang++
CXXFLAGS	?=	-Wall -Wextra -Werror
CXXFLAGS	+=	-I../include -ISFML-2.2/include

LDFLAGS		=	-shared -fPIC
LDFLAGS		+=	-LSFML-2.2/lib
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
