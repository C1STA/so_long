/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:25:06 by wcista            #+#    #+#             */
/*   Updated: 2022/12/03 18:41:04 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "includes/get_next_line.h"

int	main(int ac, char *av[])
{
	char	*map;

	map = "";
	if (ac == 2)
	{
		map = get_map(map, av);
		extension_check(av[1], map);
		is_rectangle(map);
		parsing(map);
		pathfinding(map);
		//printf("%s", map);
		free(map);
	}
	return (0);
}
