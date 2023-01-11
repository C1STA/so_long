/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:45:12 by wcista            #+#    #+#             */
/*   Updated: 2023/01/11 13:23:40 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include "../libs/libft/libft.h"
# include "../libs/libft/ft_printf.h"
# include "../libs/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define IMG_SIZE 32

typedef struct s_map
{
	int		x;
	int		y;
	int		item;
	int		x_pos;
	int		y_pos;
	int		x_exit;
	int		y_exit;
	char	**map;
}	t_map;
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		img_pxl;
	void	*img_0;
	void	*img_1;
	void	*img_e;
	void	*img_c;
	void	*img_p;
	void	*img_p_top;
	void	*img_p_left;
	void	*img_p_right;
	void	*img_h;
}	t_mlx;

typedef struct s_vars
{
	t_mlx	x;
	t_map	m;
	int		move_counter;
}	t_v;

char	**get_map(char *av[], t_v *v);
void	error_return(t_v *v, int n);
void	extension_check(char *str);
void	is_valid(t_v *v);
void	is_rectangle(t_v *v);
void	is_wall(t_v *v);
void	is_items(t_v *v);
void	free_map(t_v *v);
void	free_tmp(char **map, t_v *v);
int		free_mlx(t_v *v);
int		keypress_events(int keysym, t_v *v);
void	put_object_to_window(t_v *v, int y, int x, int n);
void	destroy_images(t_v *v);
void	is_playable(char *av[], t_v *v);
void	get_sprites(t_v *v);
void	display_map(t_v *v);
void	display_objects(t_v *v, int n);
int		display_moves(t_v *v);

#endif