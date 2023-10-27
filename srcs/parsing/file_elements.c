/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:33:31 by itchinda          #+#    #+#             */
/*   Updated: 2023/10/27 23:05:23 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "utils.h"

int	first_element(char *elem)
{
	if (!ft_strncmp(elem, "A", ft_strlen(elem)))
		return (AMBIENT);
	else if (!ft_strncmp(elem, "L", ft_strlen(elem)))
		return (LIGHT);
	else if (!ft_strncmp(elem, "C", ft_strlen(elem)))
		return (CAMERA);
	else if (!ft_strncmp(elem, "sp", ft_strlen(elem)))
		return (SPHERE);
	else if (!ft_strncmp(elem, "cy", ft_strlen(elem)))
		return (CYLINDER);
	else if (!ft_strncmp(elem, "pl", ft_strlen(elem)))
		return (PLAN);
	else if (!ft_strncmp(elem, "co", ft_strlen(elem)))
		return (CONE);
	else if (!ft_strncmp(elem, "tr", ft_strlen(elem)))
		return (TRIANGLE);
	return (-1);
}

static bool	ft_isint(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int	add_dimension(t_data	*data, char **elems)
{
	data->nb_dimension++;
	if (data->nb_dimension > 1)
		return (printf("Error: R should be declared only once\n"), 1);
	if (ft_tabsize(elems) != 3)
		return (printf("Error: R should have 2 arguments\n"), 1);
	if (!ft_isint(elems[1]) || !ft_isint(elems[2]))
		return (printf("Error: R arguments should be a interger\n"), 1);
	data->width = ft_atoi(elems[1]);
	data->height = ft_atoi(elems[2]);
	if (data->height < 0 || data->width < 0)
		return (printf("Error: R arguments should be positive\n"), 1);
	if (data->width > 1920)
		data->width = W_W;
	if (data->height > 1080)
		data->height = W_W;
	return (0);
}

int	add_to_struct_suite(t_data *data, int type, char **elems)
{
	int		ret;

	ret = -1;
	if (type == AMBIENT)
		ret = add_ambient(data, elems);
	else if (type == LIGHT)
		ret = add_light(data, elems);
	else if (type == CAMERA)
		ret = add_camera(data, elems);
	else if (type == DIMENSIONS)
		ret = add_dimension(data, elems);
	return (ret);
}

int	add_to_struct(t_data *data, int type, char *line)
{
	char	**elems;
	int		ret;

	elems = ft_split(line, ' ');
	ret = -1;
	if (!elems)
		return (ERROR);
	if (type == -1)
		ret = write(STDERR_FILENO, ERR_NAME_ELMT, 31);
	else if (type == SPHERE)
		ret = add_a_sphere(data, elems);
	else if (type == CYLINDER)
		ret = add_a_cylindre(data, elems);
	else if (type == PLAN)
		ret = add_a_plan(data, elems);
	else if (type == TRIANGLE)
		ret = add_a_triangle(data, elems);
	else if (type == CONE)
		ret = add_a_cone(data, elems);
	else
		ret = add_to_struct_suite(data, type, elems);
	ft_freearr(elems);
	return (ret);
}
