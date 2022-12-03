/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:45:12 by wcista            #+#    #+#             */
/*   Updated: 2022/12/03 18:38:35 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_program
{
	void	*mlx_pointer;
	void	*window;
}	t_program;

char	*get_map(char *map, char *av[]);
void	pathfinding(char *map);
void	error_return(char *map);
void	extension_check(char *str, char *map);
void	is_rectangle(char *map);
void	parsing(char *map);

#endif