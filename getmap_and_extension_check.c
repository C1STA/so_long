/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap_and_extension_check.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:35:12 by wcista            #+#    #+#             */
/*   Updated: 2023/01/05 15:11:40 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	get_map_size(char *av[], t_v *v)
{
	int			fd;
	char		*map;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_return(v, 8);
	map = get_next_line(fd);
	if (!map)
		error_return(v, 9);
	v->m.x = (int)ft_strlen(map);
	free(map);
	v->m.y = 1;
	while (map)
	{
		map = get_next_line(fd);
		if (map)
			v->m.y++;
		free(map);
	}
	close(fd);
}

char	**get_map(char *av[], t_v *v)
{
	int		fd;
	int		i;
	char	**map;

	i = 0;
	get_map_size(av, v);
	map = malloc(v->m.y * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_return(v, 8);
	map[i] = get_next_line(fd);
	i++;
	while (i < v->m.y)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}

void	extension_check(char *str)
{
	char	*ext;
	int		i;
	int		j;

	ext = ".ber";
	i = (int)ft_strlen(str) - 4;
	j = 0;
	if ((i + 4) > 4)
	{
		while (str[i])
		{
			if (str[i] != ext[j])
			{
				write(2, "Error\nWrong extension name.\n", 28);
				exit(EXIT_FAILURE);
			}
			i++;
			j++;
		}
	}
	else
	{
		write(2, "Error\nWrong extension name.\n", 28);
		exit(EXIT_FAILURE);
	}
}
