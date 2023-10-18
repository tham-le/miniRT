#include "miniRT.h"
#include <stdlib.h>

int	check_extension(char *file_name)
{
	char	*ext;

	if (!ft_strchr(file_name, '.'))
		return (1);
	ext = file_name + ft_strlen(file_name) - 3;
	if (ft_strncmp(ext, ".rt", ft_strlen(ext)))
		return (1);
	return (0);
}

int parse_input(int ac, char **av)
{
	char	*buffer;
	int		file_no;

	(void)ac;
	buffer = malloc(sizeof(int));
	if (!buffer)
		return (1);
	if (check_extension(av[1]))
		return (free(buffer), printf("Error: %s is not a .rt file\n", av[1]), 1);
	file_no = open(av[1], O_RDONLY);
	if (file_no == -1)
		return (free(buffer), printf("Error: %s cannot be opened\n", av[1]), 1);
	if (!read(file_no, buffer, sizeof(int)))
		return (free(buffer), close(file_no), printf("Error: file %s is empty\n", av[1]), 1);
	close(file_no);
	free(buffer);
	return (0);
}

int get_type(char *line)
{
	char	**tab;

	tab = ft_split(line, ' ');
	if (!ft_strncmp(tab[0], "A", ft_strlen(tab[0])))
		return (ft_freearr(tab), AMBIENT);
	else if (!ft_strncmp(tab[0], "C", ft_strlen(tab[0])))
		return (ft_freearr(tab), CAMERA);
	else if (!ft_strncmp(tab[0], "L", ft_strlen(tab[0])))
		return (ft_freearr(tab), LIGHT);
	else if (!ft_strncmp(tab[0], "sp", ft_strlen(tab[0])))
		return (ft_freearr(tab), SPHERE);
	else if (!ft_strncmp(tab[0], "cy", ft_strlen(tab[0])))
		return (ft_freearr(tab), CYLINDER);
	else if (!ft_strncmp(tab[0], "pl", ft_strlen(tab[0])))
		return (ft_freearr(tab), PLAN);
	else if (!ft_strncmp(tab[0], "co", ft_strlen(tab[0])))
		return (ft_freearr(tab), CONE);
	else if (!ft_strncmp(tab[0], "tr", ft_strlen(tab[0])))
		return (ft_freearr(tab), TRIANGLE);
	else if (!ft_strncmp(tab[0], "R", ft_strlen(tab[0])))
		return (ft_freearr(tab), DIMENSIONS);
	else if (!ft_strncmp(tab[0], "//", 2))
		return (ft_freearr(tab), COMMENT);
	else if (!ft_strncmp(tab[0], "#", 1))
		return (ft_freearr(tab), COMMENT);
	else
		return (ft_freearr(tab), -1);
}

int	init_and_parse(t_data *data, char **av)
{
	int		file_no;
	char	*line;
	char	*sp_line;
	int		type;

	file_no = open(av[1], O_RDONLY);
	// init_scene(data);
	while (1)
	{
		line = get_next_line(file_no);
		if (!line)
			break ;
		sp_line = spaces_check(line);
		free(line);
		if (!sp_line)
			continue ;
		type = get_type(sp_line);
		data->nb_lines++;
		if (add_to_struct(data, type, sp_line) > 0)
		{
			get_next_line(-1);
			free(sp_line);
			close(file_no);
			return (1);
		}
		free(sp_line);
	}
	if(!data->nb_lines)
		return(printf("Error: file %s is empty\n", av[1]), 1);
	close(file_no);
	return (0);
}

int	parsing(t_data *data, int ac, char **av)
{
	if (parse_input(ac, av))
		return (1);
	if (init_and_parse(data, av))
		return (1);
	return (0);
}
