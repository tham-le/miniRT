/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:20:40 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/10 19:56:45 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*  */

# define SUCESS 0
# define ERROR 1


# define W_WIDTH 900
# define W_HEIGHT 900


#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <float.h>

# include <mlx.h>
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

#include "structs.h"
#include "utils.h"
#include "libft.h"
#include "parsing.h"

/*
*	Structures
*/

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_scene	*scene;
	t_objs	*objs;
}				t_data;

#endif
