/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:12:47 by wcista            #+#    #+#             */
/*   Updated: 2022/06/24 13:58:50 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;
	char	*p_dest;
	char	*p_src;

	p_dest = (char *)dest;
	p_src = (char *)src;
	i = 0;
	if ((p_dest != NULL) && (p_src != NULL))
	{
		while (i < size)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	return (p_dest);
}
