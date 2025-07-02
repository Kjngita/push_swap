NAME = push_swap_lib.a

CFILES = go_thru_args.c \
	ps_atoi.c

OFILES = $(CFILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADER = ps_header.h

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

test: ps_main.c $(NAME)
	cc $(FLAGS) -g $^ -o cuckoo
	./cuckoo

.SILENT:

.PHONY: all clean fclean re test
