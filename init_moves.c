/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:18:53 by wcista            #+#    #+#             */
/*   Updated: 2023/01/09 08:03:05 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_draw_player(t_v *v, int keysym)
{
	if (keysym == XK_W || keysym == XK_w)
		keysym = ft_check_player_up(v);
	if (keysym == XK_S || keysym == XK_s)
		keysym = ft_check_player_down(v);
	if (keysym == XK_D || keysym == XK_d)
		keysym = ft_check_player_right(v);
	if (keysym == XK_A || keysym == XK_a)
		keysym = ft_check_player_left(v);
	if (keysym == 1)
		mlx_put_image_to_window(v->x.mlx, v->x.win, v->ig.img, 0, 0);
}

int	keypress_events(int keysym, t_v *v)
{
	if (keysym == XK_W || keysym == XK_w)
		move(v, v->m.y_pos - 1, v->m.x_pos);
	if (keysym == XK_S || keysym == XK_s)
		move(v, v->m.y_pos + 1, v->m.x_pos);
	if (keysym == XK_A || keysym == XK_a)
		move(v, v->m.y_pos, v->m.x_pos - 1);
	if (keysym == XK_D || keysym == XK_d)
		move(v, v->m.y_pos, v->m.x_pos + 1);
	if (keysym == XK_Escape)
	{
		free_map(v);
		free_mlx(v);
	}
	return (0);
}

void	moves(t_v *v, int y, int x)
{
	if (v->m.map[y][x] != '1')
	{
		if (v->m.map[y][x] == 'E' && !v->m.item)
		{
			
		}
		if (v->m.map[y][x] == 'C' || v->m.map[y][x] == '0')
		{
			if (v->m.map[y][x] == 'C')
				v->m.item--;
			v->m.map[y][x] = 'P';
			v->m.map[v->m.y_pos][v->m.x_pos] = '0';
			v->m.x_pos = x;
			v->m.y_pos = y;
		}
		display_objects(v);
	}
}
