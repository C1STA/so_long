/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:18:53 by wcista            #+#    #+#             */
/*   Updated: 2023/01/11 14:48:45 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	end_move(t_v *v, int y, int x, int n)
{
	ft_printf("Moves : %d\n", v->move_counter + 1);
	if (v->m.map[y][x] == 'E')
		ft_printf("YOU WIN !\n");
	else
		ft_printf("GAME OVER !\n");
	v->m.map[y][x] = 'P';
	v->m.map[v->m.y_pos][v->m.x_pos] = '0';
	display_objects(v, n);
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

void	move(t_v *v, int y, int x, int n)
{
	if (v->m.map[y][x] != '1')
	{
		if (v->m.y_pos == v->m.y_exit && v->m.x_pos == v->m.x_exit)
			v->m.map[v->m.y_pos][v->m.x_pos] = 'E';
		if (v->m.map[y][x] == 'E' && !v->m.item)
			end_move(v, y, x, n);
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
			end_move(v, y, x, n);
		v->move_counter++;
		ft_printf("Moves : %d\n", v->move_counter);
		display_objects(v, n);
	}
	else
		put_object_to_window(v, v->m.y_pos, v->m.x_pos, n);
}

int	keypress_events(int keysym, t_v *v)
{
	if (keysym == XK_W || keysym == XK_w)
		move(v, v->m.y_pos - 1, v->m.x_pos, 0);
	if (keysym == XK_S || keysym == XK_s)
		move(v, v->m.y_pos + 1, v->m.x_pos, 1);
	if (keysym == XK_A || keysym == XK_a)
		move(v, v->m.y_pos, v->m.x_pos - 1, 2);
	if (keysym == XK_D || keysym == XK_d)
		move(v, v->m.y_pos, v->m.x_pos + 1, 3);
	if (keysym == XK_Escape)
		free_mlx(v);
	return (0);
}
