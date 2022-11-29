/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_pathfinding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:01:23 by wcista            #+#    #+#             */
/*   Updated: 2022/11/29 19:32:34 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "includes/get_next_line.h"


void	error_multiple_free(char *map, char *t_map)
{
	free(map);
	free(t_map);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	coordinates(int i, int n, char *t_map, char *map)
{
	int	x;

	x = 0;
	if (map[i + 1] != 'E' && map[i + 1] != '1')
	{
		x++;
		map[i + 1] == 'P';
	}
	if (map[i - 1] != 'E' && map[i + 1] != '1')
	{
		x++;
		map[i - 1] == 'P';
	}
	if (map[i + n] != 'E' && map[i + n] != '1')
	{
		x++;
		map[i + n] == 'P';
	}
	if (map[i - n] != 'E' && map[i - n] != '1')
	{
		x++;
		map [i - n] == 'P';
	}
	if (x == 0)
		error_return(map, t_map);
}

/* int	item_calculator(int i, int n, int item, char *map)
{
	if (map[i + 1] == 'C')
		item--;
	if (map[i - 1] == 'C')
		item--;
	if (map[i + n] == 'C')
		item--;
	if (map[i - n] == 'C')
		item--;
	return (item);
} */

void	pathfind(char *map, char *t_map)
{
	int	i;
	int	len;
	int	item;
	int	n;

	n = seperator(t_map);
	i = n + 1;
	item = how_much_items(map);
	len = ft_strlen(t_map);
	while (i < (len - n))
	{
		if (t_map[i] == 'P')
			coordinates(i, n, t_map, map);
		i++;
	}
	pathfind(map, t_map);
	if (item != 0)
		error_multiple_free(map, t_map);
}
