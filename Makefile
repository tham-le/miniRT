NAME = miniRT

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(addprefix $(LIBFT_DIR)/, fd_printf.c ft_atoi.c ft_bzero.c ft_freearr.c ft_itoa.c ft_split.c ft_strchr.c ft_strcjoin.c ft_strcmp.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strrchr.c ft_strstr.c ft_subarr.c ft_substr.c ft_tabsize.c ft_lstadd_back.c ft_atod.c)

PARSING_DIR = src/parsing
PARSE = $(addprefix $(PARSING_DIR)/, parsing.c file_elements.c add_objs_elems.c add_scene_elems.c infos_elements.c print_struct.c)

UTILS_DIR = src/utils
UTILS = $(addprefix $(UTILS_DIR)/, gnl.c)

SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, main.c)

OBJS = $(SRCS:.c=.o) $(PARSE:.c=.o) $(UTILS:.c=.o) $(LIBFT:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re