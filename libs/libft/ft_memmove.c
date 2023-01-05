/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:25:30 by wcista            #+#    #+#             */
/*   Updated: 2022/06/24 16:49:36 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;
	char	*p_dest;
	char	*p_src;

	p_dest = (char *)dest;
	p_src = (char *)src;
	i = 0;
	if (p_src > p_dest)
	{
		while (i < size)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	else
	{
		while (i != size)
		{
			p_dest[size - i - 1] = p_src[size - i - 1];
			i++;
		}
	}
	return (dest);
}
