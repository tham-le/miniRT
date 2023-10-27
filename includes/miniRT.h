/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:20:40 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 21:32:16 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*  */

# define SUCESS 0
# define ERROR 1

# define MAX_INTERSECT 200

# define W_W 980
# define W_H 540

# define DEG_2_RAD 0.0174532925
// PI/180
# define RAD_2_DEG 57.2957795786
//180/3.14159265

# define SP 0.5
//CAM_SPEED

# define EPSILON 0.001f
# define ERR_MALLOC "\033[1;31mError: malloc failed\033[0m\n"

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <float.h>
# include <stdbool.h>

# include <mlx.h>
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

# include "structs.h"
# include "utils.h"
# include "libft.h"
# include "parsing.h"
# include "hook.h"
# include "render.h"
# include "mathRT.h"

#endif
