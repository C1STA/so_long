/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:20:26 by wcista            #+#    #+#             */
/*   Updated: 2022/11/26 02:10:14 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "includes/get_next_line.h"

void	error_return(char *map)
{
	free(map);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	is_rectangle(char *map)
{
	int	i;
	int	h;
	int	w;
	int	n;

	i = 0;
	h = 0;
	w = 0;
	n = -1;
	while (map[h] != '\n')
		h++;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (i - n != (h + 1))
				error_return(map);
			n = i;
			w++;
		}
		i++;
	}
	if ((h == (w + 1)) || ((int)ft_strlen(map) - 1) - n != (h)
		|| (h) < 3 || (w + 1 < 3))
		error_return(map);
}

void	parsing(char *map)
{
	int	exit;
	int	pos;
	int	i;
	int	len;

	exit = 0;
	pos = 0;
	i = 0;
	len = ft_strlen(map) - 1;

	while (map[i] && line == 0)
	{
		if (map[i] != 1)
			error_return(map);
		i++;
	}
	while (map[i] && line != 0)
	{
		if (map[0] != 1)
			error_return();
		if (map[i] == len && map[i] != 1)
			error_return(map);
		if (map[i] == 'E')
			exit++;
		if (map[i] == 'P')
			pos++;
		i++;
	}
	if (exit || exit > 1)
		error_return(map);
	if (pos || pos > 1)
		error_return(map);
}

int	get_map_size(char *map, char *av[])
{
	int	fd;
	int	len;

	len = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	while (map)
	{
		map = get_next_line(fd);
		if (map)
			len += ft_strlen(map);
		free(map);
	}
	close(fd);
	return (len);
}

char	*get_map(char *map, char *av[])
{
	int		fd;
	int		len;
	int		i;
	int		j;
	char	*full_map;

	j = 0;
	len = get_map_size(map, av) + 1;
	full_map = malloc(len * sizeof(char));
	if (!full_map)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	while (map)
	{
		map = get_next_line(fd);
		if (map)
		{
			i = 0;
			while (map[i])
				full_map[j++] = map[i++];
		}
		free(map);
	}
	full_map[j] = '\0';
	return (full_map);
}

int	main(int ac, char *av[])
{
	char	*map;

	map = "";
	if (ac == 2)
	{
		map = get_map(map, av);
		is_rectangle(map);
		printf("%s", map);
		free(map);
	}
	return (0);
}

/* int	main(void)
{
	char	*map;

	map = "111\n111\n111\n111";
	is_rectangle(map);
} */
