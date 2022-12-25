/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:45:12 by wcista            #+#    #+#             */
/*   Updated: 2022/12/25 18:47:22 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_image
{
	void	*pointer;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_image;

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

typedef enum e_sprites
{
	s
}

char	*get_map(char *map, char *av[]);
void	pathfinding(char *map);
void	error_return(char *map, int n);
void	extension_check(char *str);
void	is_rectangle(char *map);
void	parsing(char *map);

#endif