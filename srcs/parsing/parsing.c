/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:40:25 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 22:34:39 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdlib.h>

int	parse_input(int ac, char **av)
{
	char	*buffer;
	int		file_no;

	(void)ac;
	buffer = malloc(sizeof(int));
	if (!buffer)
		return (ERROR);
	if (check_extension(av[1]))
		return (free(buffer), printf("Error: %s is not a .rt file\n", av[1]), 1);
	file_no = open(av[1], O_RDONLY);
	if (file_no == -1)
		return (free(buffer), printf("Error: %s cannot be opened\n", av[1]), 1);
	if (!read(file_no, buffer, sizeof(int)))
		return (free(buffer), close(file_no), printf("Error: file %s is empty\n",
				av[1]), 1);
	if (close(file_no) == -1)
		return (free(buffer), printf("Error: %s cannot be closed\n", av[1]), 1);
	free(buffer);
	return (0);
}

int	get_type_suite(char **tab)
{
	if (!ft_strcmp(tab[0], "co"))
		return (ft_freearr(tab), CONE);
	else if (!ft_strcmp(tab[0], "tr"))
		return (ft_freearr(tab), TRIANGLE);
	else if (!ft_strcmp(tab[0], "R"))
		return (ft_freearr(tab), DIMENSIONS);
	else if (!ft_strncmp(tab[0], "//", 2))
		return (ft_freearr(tab), COMMENT);
	else if (!ft_strncmp(tab[0], "#", 1))
		return (ft_freearr(tab), COMMENT);
	else
		return (ft_freearr(tab), -1);
}

int	get_type(char *line)
{
	char	**tab;

	tab = ft_split(line, ' ');
	if (!tab)
		return (-42);
	if (!ft_strcmp(tab[0], "A"))
		return (ft_freearr(tab), AMBIENT);
	else if (!ft_strcmp(tab[0], "C"))
		return (ft_freearr(tab), CAMERA);
	else if (!ft_strcmp(tab[0], "L"))
		return (ft_freearr(tab), LIGHT);
	else if (!ft_strcmp(tab[0], "sp"))
		return (ft_freearr(tab), SPHERE);
	else if (!ft_strcmp(tab[0], "cy"))
		return (ft_freearr(tab), CYLINDER);
	else if (!ft_strcmp(tab[0], "pl"))
		return (ft_freearr(tab), PLAN);
	else
		return (get_type_suite(tab));
}

/*no need to protect open here because we did check in parse_input*/
int	init_and_parse(t_data *data, char **av)
{
	int		file_no;
	char	*line;
	char	*sp_line;
	int		type;

	file_no = open(av[1], O_RDONLY);
	data->nb_lines = 0;
	while (1)
	{
		line = get_next_line(file_no);
		if (!line)
			break ;
		sp_line = spaces_check(line);
		free(line);
		data->nb_lines++;
		if (!sp_line)
			continue ;
		type = get_type(sp_line);
		if (type == -42 || add_to_struct(data, type, sp_line) > 0)
			return (get_next_line(-1), free(sp_line), close(file_no), 1);
		free(sp_line);
	}
	if (!data->nb_lines)
		return (printf("Error: file %s is empty\n", av[1]), 1);
	return (close(file_no), 0);
}

int	parsing(t_data *data, int ac, char **av)
{
	if (parse_input(ac, av))
		return (ERROR);
	if (init_and_parse(data, av))
		return (ERROR);
	if (!data->scene.nb_cam)
		return (printf("Error: you need at leat one camera\n"), ERROR);
	if (!data->scene.nb_light)
		return (printf("Error: you need at leat one light\n"), ERROR);
	if (!data->scene.nb_amb)
		return (printf("Error: you need at leat one ambient\n"), ERROR);
	return (SUCESS);
}
