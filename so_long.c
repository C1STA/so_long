/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:25:06 by wcista            #+#    #+#             */
/*   Updated: 2023/01/09 16:47:11 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char *av[])
{
	t_v	*v;

	if (ac != 2)
		return (ft_printf("Error\nNo arg or multiple args found.\n"), 1);
	extension_check(av[1]);
	v = (t_v *)malloc(sizeof(t_v));
	if (!v)
		return (1);
	v->m.map = get_map(av, v);
	is_valid(v);
	is_playable(av, v);
	display_map(v);
	return (0);
}
