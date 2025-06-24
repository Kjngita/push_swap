NAME = push_swap

CFILES = 

OFILES = $(CFILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADER = 

$(NAME): $(OFILES)
	ar -rcs $(NAME) $(OFILES)

$(OFILES): $(CFILES)
	cc $(FLAGS) -c $^

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SILENT:

.PHONY: all clean fclean re
