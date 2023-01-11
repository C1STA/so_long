/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:52:23 by wcista            #+#    #+#             */
/*   Updated: 2023/01/11 14:32:32 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	display_moves(t_v *v)
{
	char	*str;

	mlx_string_put(v->x.mlx, v->x.win, 12,
		((v->m.y * 32) - 30), 0x00CC3300, "Moves :");
	str = ft_itoa(v->move_counter);
	mlx_string_put(v->x.mlx, v->x.win, 59,
		((v->m.y * 32) - 30), 0x00CC3300, str);
	free(str);
	return (0);
}

void	put_player_position(t_v *v, int y, int x, int n)
{
	if (n == 0)
		mlx_put_image_to_window(v->x.mlx, v->x.win, v->x.img_p_top, x, y);
	if (n == 1)
		mlx_put_image_to_window(v->x.mlx, v->x.win, v->x.img_p, x, y);
	if (n == 2)
		mlx_put_image_to_window(v->x.mlx, v->x.win, v->x.img_p_left, x, y);
	if (n == 3)
		mlx_put_image_to_window(v->x.mlx, v->x.win, v->x.img_p_right, x, y);
}

void	put_object_to_window(t_v *v, int y, int x, int n)
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
		put_player_position(v, y_, x_, n);
	if (v->m.map[y][x] == 'H')
		mlx_put_image_to_window(v->x.mlx, v->x.win, v->x.img_h, x_, y_);
}

void	display_objects(t_v *v, int n)
{
	int	y;
	int	x;

	y = 0;
	while (y < v->m.y)
	{
		x = 0;
		while (v->m.map[y][x])
		{
			put_object_to_window(v, y, x, n);
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
	v->x.win = mlx_new_window(v->x.mlx, (v->x.img_pxl * (v->m.x - 1)),
			(v->x.img_pxl * v->m.y), "so_long");
	if (!v->x.win)
		error_return(v, 13);
	display_objects(v, 1);
	mlx_hook(v->x.win, KeyPress, KeyPressMask, &keypress_events, v);
	mlx_hook(v->x.win, DestroyNotify, StructureNotifyMask, &free_mlx, v);
	mlx_loop_hook(v->x.mlx, display_moves, v);
	mlx_loop(v->x.mlx);
}
