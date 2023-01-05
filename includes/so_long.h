/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:45:12 by wcista            #+#    #+#             */
/*   Updated: 2023/01/05 15:11:06 by wcista           ###   ########.fr       */
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

typedef struct s_image
{
	void	*pointer;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_image;

typedef struct s_map
{
	int		x;
	int		y;
	int		x_pos;
	int		y_pos;
	char	**map;
}	t_map;

typedef struct s_program
{
	void	*mlx_pointer;
	void	*window;
	t_image	towel;
}	t_program;

typedef enum e_movements
{
	W,
	S,
	A,
	D
}	t_movements;

/* typedef enum e_sprites
{
	s
} */

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	m;
}	t_v;

char	**get_map(char *av[], t_v *v);
void	error_return(t_v *v, int n);
void	extension_check(char *str);
void	is_valid(t_v *v);
void	free_map(t_v *v);
void	free_tmp(char **map, t_v *v);
void	is_playable(char *av[], t_v *v);
void	get_map_size(char *av[], t_v *v);

#endif