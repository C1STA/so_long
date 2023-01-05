/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:17:58 by wcista            #+#    #+#             */
/*   Updated: 2023/01/05 15:02:55 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	is_rectangle(t_v *v)
{
	int	i;

	i = 1;
	if (v->m.x > 49 || v->m.y > 28)
		error_return(v, 11);
	if (v->m.x <= 3 || v->m.y < 3)
		error_return(v, 10);
	if (v->m.x - 1 == v->m.y)
		error_return(v, 1);
	while (i < v->m.y)
	{
		if ((int)ft_strlen(v->m.map[i - 1]) != v->m.x)
			error_return(v, 1);
		i++;
	}
	if ((int)ft_strlen(v->m.map[i - 1]) != v->m.x - 1)
		error_return(v, 1);
}

void	is_wall(t_v *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < v->m.y)
	{
		while (j < v->m.x - 1 && i == 0)
		{
			if (v->m.map[0][j] != '1' || v->m.map[v->m.y - 1][j] != '1')
				error_return(v, 2);
			j++;
		}
		if (v->m.map[i][0] != '1' || v->m.map[i][v->m.x - 2] != '1')
			error_return(v, 2);
		i++;
	}
}

void	check_items(t_v *v, int exit, int pos, int item)
{
	int	i;
	int	j;

	i = 0;
	while (i < v->m.y)
	{
		j = 0;
		while (v->m.map[i][j])
		{
			if (v->m.map[i][j] == 'E')
				exit++;
			if (v->m.map[i][j] == 'P')
				pos++;
			if (v->m.map[i][j] == 'C')
				item++;
			j++;
		}
		i++;
	}
	if (exit != 1)
		error_return(v, 4);
	if (pos != 1)
		error_return(v, 5);
	if ((!item))
		error_return(v, 6);
}

void	is_items(t_v *v)
{
	int	exit;
	int	pos;
	int	item;
	int	i;
	int	j;

	i = 0;
	exit = 0;
	pos = 0;
	item = 0;
	while (i < v->m.y)
	{
		j = 0;
		while (v->m.map[i][j])
		{
			if (v->m.map[i][j] != '1' && v->m.map[i][j] != '0'
			&& v->m.map[i][j] != 'C' && v->m.map[i][j] != 'E'
			&& v->m.map[i][j] != 'P' && v->m.map[i][j] != '\n')
				error_return(v, 3);
			j++;
		}
		i++;
	}
	check_items(v, exit, pos, item);
}

void	is_valid(t_v *v)
{
	is_rectangle(v);
	is_wall(v);
	is_items(v);
}
