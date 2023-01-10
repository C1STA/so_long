/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 02:34:51 by wcista            #+#    #+#             */
/*   Updated: 2023/01/10 18:31:27 by wcista           ###   ########.fr       */
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

int	free_mlx(t_v *v)
{
	mlx_destroy_image(v->x.mlx, v->x.img_0);
	mlx_destroy_image(v->x.mlx, v->x.img_1);
	mlx_destroy_image(v->x.mlx, v->x.img_e);
	mlx_destroy_image(v->x.mlx, v->x.img_c);
	mlx_destroy_image(v->x.mlx, v->x.img_p);
	mlx_destroy_image(v->x.mlx, v->x.img_h);
	mlx_destroy_image(v->x.mlx, v->x.img_p_top);
	mlx_destroy_image(v->x.mlx, v->x.img_p_left);
	mlx_destroy_image(v->x.mlx, v->x.img_p_right);
	mlx_destroy_window(v->x.mlx, v->x.win);
	mlx_destroy_display(v->x.mlx);
	free(v->x.mlx);
	free_map(v);
	free(v);
	exit (0);
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
	if (v->x.img_h)
		mlx_destroy_image(v->x.mlx, v->x.img_h);
	if (v->x.img_p_top)
		mlx_destroy_image(v->x.mlx, v->x.img_p_top);
	if (v->x.img_p_left)
		mlx_destroy_image(v->x.mlx, v->x.img_p_left);
	if (v->x.img_p_right)
		mlx_destroy_image(v->x.mlx, v->x.img_p_right);
	mlx_destroy_display(v->x.mlx);
	free(v->x.mlx);
}
