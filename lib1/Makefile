NAME		=	lib1.so
SRC			=	$(shell ls | grep ".cpp")
OBJ			=	$(subst .cpp,.o,$(SRC))

CXX			?=	clang++
CXXFLAGS	?=	-Wall -Wextra -Werror
CXXFLAGS	+=	-I../include
LDFLAGS		=	-shared -fPIC

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(LDFLAGS) -o $(NAME) $(OBJ)

re: fclean all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
