NAME		=	lib3.so
SRC			=	$(shell ls | grep ".cpp")
OBJ			=	$(subst .cpp,.o,$(SRC))

CPP			?=	clang++
CPPFLAGS	?=	-Wall -Wextra -Werror -std=c++11
CPPFLAGS	+=	-I../include -Iglfw/include -fPIC

LDFLAGS		=	-shared -undefined dynamic_lookup

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(LDFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $<

re: fclean
	$(MAKE) all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
