/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 02:34:51 by wcista            #+#    #+#             */
/*   Updated: 2023/01/06 15:36:59 by wcista           ###   ########.fr       */
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

void	free_mlx(t_v *v)
{
	mlx_destroy_image(v->x.mlx, v->x.img_0);
	mlx_destroy_image(v->x.mlx, v->x.img_1);
	mlx_destroy_image(v->x.mlx, v->x.img_e);
	mlx_destroy_image(v->x.mlx, v->x.img_c);
	mlx_destroy_image(v->x.mlx, v->x.img_p);
	mlx_destroy_window(v->x.mlx, v->x.win);
	mlx_destroy_display(v->x.mlx);
	free(v->x.mlx);
}

void	destroy_images(t_v *v)
{
	if (v->x.img_0)
		mlx_destroy_image(v->x.mlx, v->x.img_0);
	if (v->x.img_1)
		mlx_destroy_image(v->x.mlx, v->x.img_1);
	if (v->x.img_e)
		mlx_destroy_image(v->x.mlx, v->x.img_e);
	if (v->x.img_c)
		mlx_destroy_image(v->x.mlx, v->x.img_c);
	if (v->x.img_p)
		mlx_destroy_image(v->x.mlx, v->x.img_p);
	mlx_destroy_display(v->x.mlx);
	free(v->x.mlx);
}
