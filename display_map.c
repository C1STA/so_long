/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:52:23 by wcista            #+#    #+#             */
/*   Updated: 2023/01/06 16:47:55 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_object_to_window(t_v *v, int y, int x)
{
	int	x_;
	int	y_;

	x_ = x * IMG_SIZE;
	y_ = y * IMG_SIZE;
	if (v->m.map[y][x] == '0')
		mlx_put_image_to_window(v->x.mlx, v->x.win, v->x.img_0, x_, y_);
	if (v->m.map[y][x] == '1')
		mlx_put_image_to_window(v->x.mlx, v->x.win, v->x.img_1, x_, y_);
	if (v->m.map[y][x] == 'E')
		mlx_put_image_to_window(v->x.mlx, v->x.win, v->x.img_e, x_, y_);
	if (v->m.map[y][x] == 'C')
		mlx_put_image_to_window(v->x.mlx, v->x.win, v->x.img_c, x_, y_);
	if (v->m.map[y][x] == 'P')
		mlx_put_image_to_window(v->x.mlx, v->x.win, v->x.img_p, x_, y_);
}

void	display_objects(t_v *v)
{
	int	y;
	int	x;

	y = 0;
	while (y < v->m.y)
	{
		x = 0;
		while (v->m.map[y][x])
		{
			put_object_to_window(v, y, x);
			x++;
		}
		y++;
	}
}

void	display_map(t_v *v)
{
	v->x.img_pxl = IMG_SIZE;
	v->x.mlx = mlx_init();
	if (!v->x.mlx)
		error_return(v, 0);
	get_sprites(v);
	v->x.win = mlx_new_window(v->x.mlx, (v->x.img_pxl * v->m.x),
			(v->x.img_pxl * v->m.y), "so_long");
	if (!v->x.win)
		error_return(v, 13);
	display_objects(v);
}
