/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:44:43 by wcista            #+#    #+#             */
/*   Updated: 2022/06/24 12:51:54 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*tab;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	if (nitems && ((nitems * size / nitems) != size))
		return (NULL);
	tab = malloc(nitems * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, nitems * size);
	return (tab);
}
