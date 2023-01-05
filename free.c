/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 02:34:51 by wcista            #+#    #+#             */
/*   Updated: 2023/01/05 15:09:36 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tmp(char **map, t_v *v)
{
	int	i;

	i = 0;
	while (i < v->m.y)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map(t_v *v)
{
	int	i;

	i = 0;
	while (i < v->m.y)
	{
		free(v->m.map[i]);
		i++;
	}
	free(v->m.map);
}
