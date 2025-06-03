# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 13:30:17 by thi-le            #+#    #+#              #
#    Updated: 2023/10/27 22:28:41 by thi-le           ###   ########.fr        #
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
INC			= -g3 -I $(INCLUDE) -I$(LIBFT_DIR) -I$(MLX_DIR)\

#OPTI_FLAGS	= -O3 
OPTI_FLAGS	= -O3 -march=native -flto -ffast-math -fforce-addr -fno-plt
#THR_FLAGS	= -pthread


CFLAGS		= -g3 -Werror -Wextra -Wall $(OPTI_FLAGS) $(INC)

LFLAGS		= -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz\
			-L$(LIBFT_DIR) -lft

RM			= rm -rf

#Sources


SRC_FILES	=	main.c

#render
RENDER_DIR		=	render/
RENDER_FILES	=	camera.c\
					get_obj_color.c\
					get_rgb.c\
					intersect.c\
					intersect_cone.c\
					intersect_cylinder.c\
					intersect_sphere.c\
					intersect_triangle.c\
					normal_at.c\
					pre_computation.c\
					ray_to_pixel.c\
					reflection.c\
					render.c\
					set_color.c\
					specular_and_diffuse.c\
					transform.c\
					uv_map.c

SRC_FILES		+=	$(addprefix $(RENDER_DIR), $(RENDER_FILES))

#hooks
HOOKS_DIR	=	hook/
HOOKS_FILES	=	hook.c move_camera.c
SRC_FILES	+=	$(addprefix $(HOOKS_DIR), $(HOOKS_FILES))

#parse
PARSE_DIR	=	parsing/
PARSE_FILES	=	add_a_cone.c\
				add_a_cylindre.c\
				add_a_plan.c\
				add_a_sphere.c\
				add_a_triangle.c\
				add_objs_elems.c\
				add_options.c\
				add_scene_elems.c\
				check_extension.c\
				file_elements.c\
				infos.c\
				infos_elements.c\
				init_scene.c\
				options.c\
				parse_file.c\
				parse_helpers.c\
				parsing.c\
				range_check.c

SRC_FILES	+=	$(addprefix $(PARSE_DIR), $(PARSE_FILES))

#math_operations
MATH_DIR	=	math/
MATH_FILES	=	mat_operation1.c mat_operation2.c mat_operation3.c\
				mat_transform.c \
				vec_operation1.c vec_operation2.c
SRC_FILES	+=	$(addprefix $(MATH_DIR), $(MATH_FILES))


#utilities
UTILS_DIR	=	utils/
UTILS_FILES	=	ft_atod.c ft_lstadd_back.c clean.c print_help.c ft_tabsize.c\
				color_operation.c init_obj_value.c ft_lstclear.c\
				ft_swapd.c ft_atoi_base.c
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
			$(SRC) $(INCLUDE) $(LIBFT_DIR)

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
