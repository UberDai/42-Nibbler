NAME		=	lib3.so
SRC			=	$(shell ls | grep ".cpp")
OBJ			=	$(subst .cpp,.o,$(SRC))

CXX			?=	clang++
CXXFLAGS	?=	-Wall -Wextra -Werror -std=c++11
CXXFLAGS	+=	-I../include -Iminilibx -fPIC

LDFLAGS		=	-shared -undefined dynamic_lookup

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(LDFLAGS) -o $(NAME) $(OBJ)

re: fclean
	$(MAKE) all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
