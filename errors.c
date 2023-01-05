/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 06:21:43 by wcista            #+#    #+#             */
/*   Updated: 2023/01/04 14:58:37 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	error_return_next(int n)
{
	if (n == 10)
		write(2, "Error\nThe map is not big enough.\n", 33);
	if (n == 11)
		write(2, "Error\nThe map is too big.\n", 26);
	exit(EXIT_FAILURE);
}

void	error_return(t_v *v, int n)
{
	if (v->m.map)
		free_map(v);
	free(v);
	if (n == 0)
		write(2, "Error\nmax\n", 10);
	if (n == 1)
		write(2, "Error\nThe map is not a rectangle.\n", 34);
	if (n == 2)
		write(2, "Error\nThe map is not surrounded by walls.\n", 42);
	if (n == 3)
		write(2, "Error\nThe map contains unknown elements.\n", 41);
	if (n == 4)
		write(2, "Error\nThe map does not contain only one exit.\n", 46);
	if (n == 5)
		write(2, "Error\nThe map does not contain only one player.\n", 48);
	if (n == 6)
		write(2, "Error\nThe map does not contain any collectibles.\n", 49);
	if (n == 7)
		write(2, "Error\nThe map is not playable.\n", 31);
	if (n == 8)
		write(2, "Error\nCould not open file descriptor.\n", 38);
	if (n == 9)
		write(2, "Error\nThe map is empty.\n", 24);
	error_return_next(n);
}
