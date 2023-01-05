/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:54:40 by wcista            #+#    #+#             */
/*   Updated: 2022/06/28 21:23:49 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	size_t				i;
	unsigned char		*p_1;
	unsigned char		*p_2;

	p_1 = (unsigned char *)p1;
	p_2 = (unsigned char *)p2;
	i = 0;
	while (i < size)
	{
		if (p_1[i] > p_2[i])
			return (1);
		else if (p_1[i] < p_2[i])
			return (-1);
		i++;
	}
	return (0);
}
