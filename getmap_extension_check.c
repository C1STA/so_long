/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap_extension_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:35:12 by wcista            #+#    #+#             */
/*   Updated: 2022/12/05 17:43:18 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "libs/libft/get_next_line.h"

int	get_map_size(char *map, char *av[])
{
	int	fd;
	int	len;

	len = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "ERROR\n", 6);
		exit(EXIT_FAILURE);
	}
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

void	extension_check(char *str, char *map)
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
				error_return(map);
			i++;
			j++;
		}
	}
	else
		error_return(map);
}
