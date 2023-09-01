NAME = miniRT

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror


PARSING_DIR = src/parsing
PARSE = $(addprefix $(PARSING_DIR)/, parsing.c)

SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, main.c)

OBJS = $(SRCS:.c=.o) $(PARSE:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re