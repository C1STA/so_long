/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:27:28 by wcista            #+#    #+#             */
/*   Updated: 2023/01/11 14:31:46 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] != '1' && map[y][x] != 'H')
	{
		if (map[y][x] != '-')
		{
			map[y][x] = '-';
			flood_fill(map, y + 1, x);
			flood_fill(map, y - 1, x);
			flood_fill(map, y, x + 1);
			flood_fill(map, y, x - 1);
		}
	}
}

void	determine_player_position(t_v *v)
{
	int	i;
	int	j;

	i = 0;
	while (i < v->m.y)
	{
		j = 0;
		while (v->m.map[i][j])
		{
			if (v->m.map[i][j] == 'P')
			{
				v->m.y_pos = i;
				v->m.x_pos = j;
				break ;
			}
			j++;
		}
		if (v->m.map[i][j])
			break ;
		i++;
	}
}

void	is_playable(char *av[], t_v *v)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	tmp = get_map(av, v);
	determine_player_position(v);
	flood_fill(tmp, v->m.y_pos, v->m.x_pos);
	while (i < v->m.y)
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == 'P' || tmp[i][j] == 'C' || tmp[i][j] == 'E')
			{
				free_tmp(tmp, v);
				error_return(v, 7);
			}
			j++;
		}
		i++;
	}
	free_tmp(tmp, v);
}
