NAME		=	lib3.so
SRC			=	$(shell ls | grep ".cpp")
OBJ			=	$(subst .cpp,.o,$(SRC))

CXX			?=	clang++
CXXFLAGS	?=	-Wall -Wextra -Werror -std=c++11
CXXFLAGS	+=	-I../include -fPIC

LDFLAGS		=	-shared -undefined dynamic_lookup
# LDFLAGS		+=	/usr/local/lib/libmlx.a -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(LDFLAGS) -o $(NAME) $(OBJ)

re: fclean all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
