/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:18:08 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/18 19:32:15 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_help(void)
{
	ft_putendl("\n Usage : miniRT <scene.rt>");
	ft_putendl("\n+====================================================+");
	ft_putendl("the scene.rt file must follow the following rules:");
	ft_putendl("Each type of element can be separated \
	by one or more line break(s)");
	ft_putendl("Each element must be separated by one or more space(s)");
	ft_putendl("Each type of element can be set in any order in the file.");
	ft_putendl("Elements which are defined by a capital letter can \
	only be declared once in the scene");
	ft_putendl("\n+====================================================+");
	ft_putendl("Available elements :");
	ft_putendl("Ambient lighting : A ambient_lighting_ratio color");
	ft_putendl("Camera : C x y z ort_x ort_y ort_z fov");
	ft_putendl("Light : L x y z light_ratio color");
	ft_putendl("Plane : pl x y z ort_x ort_y ort_z");
	ft_putendl("Sphere : sp x y z diameter color");
	ft_putendl("Cylinder : cy x y z ort_x ort_y ort_z diameter height color");
	return (0);
}
