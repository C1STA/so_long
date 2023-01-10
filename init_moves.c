/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:18:53 by wcista            #+#    #+#             */
/*   Updated: 2023/01/10 16:32:44 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	end_move(t_v *v, int y, int x, int n)
{
	v->m.map[y][x] = 'P';
	v->m.map[v->m.y_pos][v->m.x_pos] = '0';
	display_objects(v);
	ft_printf("Moves : %d\n", v->move_counter + 1);
	if (n == 0)
		ft_printf("YOU WIN !\n");
	else
		ft_printf("GAME OVER !\n");
	free_mlx(v);
}

void	normal_move(t_v *v, int y, int x)
{
	if (v->m.map[y][x] == 'C')
		v->m.item--;
	v->m.map[y][x] = 'P';
	if (v->m.y_pos != v->m.y_exit || v->m.x_pos != v->m.x_exit)
		v->m.map[v->m.y_pos][v->m.x_pos] = '0';
	v->m.x_pos = x;
	v->m.y_pos = y;
}

void	move(t_v *v, int y, int x)
{
	if (v->m.map[y][x] != '1')
	{
		if (v->m.y_pos == v->m.y_exit && v->m.x_pos == v->m.x_exit)
			v->m.map[v->m.y_pos][v->m.x_pos] = 'E';
		if (v->m.map[y][x] == 'E' && !v->m.item)
			end_move(v, y, x, 0);
		if (v->m.map[y][x] == 'C' || v->m.map[y][x] == '0')
			normal_move(v, y, x);
		if (v->m.map[y][x] == 'E')
		{
			v->m.map[y][x] = 'P';
			v->m.map[v->m.y_pos][v->m.x_pos] = '0';
			v->m.x_pos = x;
			v->m.y_pos = y;
		}
		if (v->m.map[y][x] == 'H')
			end_move(v, y, x, 1);
		v->move_counter++;
		ft_printf("Moves : %d\n", v->move_counter);
		display_objects(v);
	}
}

void	keypress_events_bonus(t_v *v, int n)
{
	int	x;
	int	y;

	x = v->m.x_pos * v->x.img_pxl;
	y = v->m.y_pos * v->x.img_pxl;
	if (n == 0)
		mlx_put_image_to_window(v->x.mlx, v->x.win, v->x.img_p_top, x, y);
	if (n == 1)
		mlx_put_image_to_window(v->x.mlx, v->x.win, v->x.img_p, x, y);
	if (n == 2)
		mlx_put_image_to_window(v->x.mlx, v->x.win, v->x.img_p_left, x, y);
	if (n == 3)
		mlx_put_image_to_window(v->x.mlx, v->x.win, v->x.img_p_right, x, y);
}

int	keypress_events(int keysym, t_v *v)
{
	if (keysym == XK_W || keysym == XK_w)
	{
		keypress_events_bonus(v, 0);
		move(v, v->m.y_pos - 1, v->m.x_pos);
	}
	if (keysym == XK_S || keysym == XK_s)
	{
		keypress_events_bonus(v, 1);
		move(v, v->m.y_pos + 1, v->m.x_pos);
	}
	if (keysym == XK_A || keysym == XK_a)
	{
		keypress_events_bonus(v, 2);
		move(v, v->m.y_pos, v->m.x_pos - 1);
	}
	if (keysym == XK_D || keysym == XK_d)
	{
		keypress_events_bonus(v, 3);
		move(v, v->m.y_pos, v->m.x_pos + 1);
	}
	if (keysym == XK_Escape)
		free_mlx(v);
	return (0);
}
