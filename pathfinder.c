/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:27:28 by wcista            #+#    #+#             */
/*   Updated: 2022/12/05 17:43:26 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "libs/libft/get_next_line.h"

void	flood_fill(char *map, int width, int y, int x)
{
	int	i;

	i = width * y + x;
	if (map[i] != '1')
	{
		if (map[i] != '-')
		{
			map[i] = '-';
			flood_fill(map, width, y + 1, x);
			flood_fill(map, width, y - 1, x);
			flood_fill(map, width, y, x + 1);
			flood_fill(map, width, y, x - 1);
		}
	}
}

int	determine_width(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (i + 1);
}

char	*tmp_map(char *map, char *map_tmp)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = ft_strlen(map);
	map_tmp = malloc((len + 1) * sizeof(char));
	if (!map_tmp)
		error_return(map);
	map_tmp[len] = '\0';
	while (map[i])
		map_tmp[j++] = map[i++];
	map[j] = '\0';
	return (map_tmp);
}

void	pathfinding(char *map)
{
	int		x;
	int		y;
	char	*map_tmp;
	int		width;

	x = 1;
	y = 1;
	map_tmp = "";
	map_tmp = tmp_map(map, map_tmp);
	width = determine_width(map_tmp);
	flood_fill(map_tmp, width, y, x);
	x = 0;
	while (map_tmp[x])
	{
		if (map_tmp[x] == 'P' || map_tmp[x] == 'C' || map_tmp[x] == 'E')
		{
			free(map_tmp);
			error_return(map);
		}
		x++;
	}
	free(map_tmp);
}
