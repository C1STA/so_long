/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:25:06 by wcista            #+#    #+#             */
/*   Updated: 2023/01/06 16:54:24 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	printmap(t_v *v)
{
	int	i;

	i = 0;
	while (i < v->m.y)
	{
		ft_printf("%s", v->m.map[i]);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_v	*v;

	if (ac != 2)
		return (write(2, "Error\nNo arg or multiple args found.\n", 48), 1);
	v = (t_v *)malloc(sizeof(t_v));
	if (!v)
		return (1);
	extension_check(av[1]);
	v->m.map = get_map(av, v);
	is_valid(v);
	is_playable(av, v);
	display_map(v);
	free_map(v);
	free_mlx(v);
	free(v);
	return (0);
}
