# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 13:30:17 by thi-le            #+#    #+#              #
#    Updated: 2023/09/10 20:02:04 by thi-le           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		= miniRT
INCLUDE		= includes/
LIBFT_DIR	= library/libft
LIBFT		= $(LIBFT_DIR)/libft.a
MLX_DIR		= library/minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a
SRC_DIR		= srcs/
OBJ_DIR		= objs/
CC			= cc
INC			= -I $(INCLUDE) -I$(LIBFT_DIR) -I$(MLX_DIR)\
			-I/usr/include

OPTI_FLAGS	= -O3
#OPTI_FLAGS	= -O3 -march=native -flto -ffast-math -fforce-addr -fno-plt
#THR_FLAGS	= -pthread


CFLAGS		= -Werror -Wextra -Wall $(OPTI_FLAGS) $(INC)

LFLAGS		= -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz\
			-L$(LIBFT_DIR) -lft

RM			= rm -rf

#Sources

SRC_FILES	=	main.c

#miniRT
MINIRT_DIR = miniRT/
MINIRT_FILES = draw.c
SRC_FILES += $(addprefix $(MINIRT_DIR), $(MINIRT_FILES))

#parse
PARSE_DIR	=	parsing/
PARSE_FILES	=	add_objs_elems.c infos_elements.c print_struct.c \
				add_scene_elems.c init_scene.c file_elements.c \
				parsing.c range_check.c parse_helpers.c
SRC_FILES	+=	$(addprefix $(PARSE_DIR), $(PARSE_FILES))

#utilities
UTILS_DIR	=	utils/
UTILS_FILES	=	ft_atod.c ft_lstadd_back.c clean.c print_help.c ft_tabsize.c
SRC_FILES	+=	$(addprefix $(UTILS_DIR), $(UTILS_FILES))


SRC		 =   $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ		 =   $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
DEP		 =   $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.d, $(SRC))
###

MAKEFLAGS += --no-print-directory

all:		$(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -MMD -MP  -c $< -o $@
			@echo "$(WHITE) $@ created  $(NOC)"

$(LIBFT):
			@make -s -C $(LIBFT_DIR)
			@echo "$(GREEN)Libft created!$(DEFAULT)"

$(MLX):
			@make -s -C $(MLX_DIR)
			@echo "$(GREEN)Mlx created!$(DEFAULT)"

$(NAME):	$(MLX) $(LIBFT) $(OBJ) Makefile
			@${CC}  ${OBJ} ${CFLAGS} ${LFLAGS} -o ${NAME}
			@echo "$(BLUE)$(NAME) created! -> Project successfully compiled"
	
-include $(DEP)

bonus:		all
	
clean:
			@$(RM) $(OBJ_DIR)
			@make -C $(LIBFT_DIR) clean 
			@echo  "$(YELLOW)Object files deleted!$(DEFAULT)"

fclean:		clean
			@$(RM) $(NAME)
			@make clean -C $(MLX_DIR) 
			@make fclean -C $(LIBFT_DIR)
			@echo "$(RED)All deleted!$(DEFAULT)"

re:			fclean all

norm:
			@norminette -R CheckForbiddenSourceHeader \
			$(SRC) $(INCLUDE) $(LIBFT) 

.PHONY:		all clean fclean re norm mlx lib bonus short
#COLORS
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m
