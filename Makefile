NAME = push_swap

CFILES = ps_main.c \
	go_thru_args.c \
	operations_swap.c operations_push.c \
	operations_rotate.c operations_revrotate.c \
	moveset1_options.c \
	moveset2_pickbest.c \
	moveset3_bringtop.c \
	cleanup.c

O_DIR = objdir

OFILES = $(addprefix $(O_DIR)/,$(CFILES:.c=.o))

FLAGS = -Wall -Wextra -Werror

HEADER = ps_header.h

all: $(NAME)

$(NAME): $(OFILES)
	cc $(FLAGS) $(OFILES) -o $(NAME)

$(O_DIR):
	mkdir -p $@

$(O_DIR)/%.o: %.c $(HEADER) | $(O_DIR)
	cc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(O_DIR) *.gch

fclean: clean
	rm -f $(NAME)

re: fclean all

.SILENT:

.PHONY: all clean fclean re
