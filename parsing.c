/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:20:26 by wcista            #+#    #+#             */
/*   Updated: 2022/12/05 17:43:21 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "libs/libft/get_next_line.h"

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
	while (map[h] != '\n' && map[h])
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

void	check_items(char *map, int exit, int pos, int item)
{
	if ((!exit) || exit > 1)
		error_return(map);
	if ((!pos) || pos > 1)
		error_return(map);
	if ((!item))
		error_return(map);
}

void	parsing_n(char *map, int i, int len)
{
	int	exit;
	int	pos;
	int	item;

	exit = 0;
	pos = 0;
	item = 0;
	while (map[i] && i <= len)
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'C'
			&& map[i] != 'E' && map[i] != 'P' && map[i] != '\n')
			error_return(map);
		if (map[i] == '\n' && (map[i + 1] != '1' || map[i - 1] != '1'))
			error_return(map);
		if (map[i] == 'E')
			exit++;
		if (map[i] == 'P')
			pos++;
		if (map[i] == 'C')
			item++;
		i++;
	}
	check_items(map, exit, pos, item);
}

void	parsing(char *map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map) - 1;
	while (map[len] != '\n')
	{
		if (map[len] != '1')
			error_return(map);
		len--;
	}
	while (map[i] != '\n')
	{
		if (map[i] != '1')
			error_return(map);
		i++;
	}
	parsing_n(map, i, len);
}
