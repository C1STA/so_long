/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:06:54 by wcista            #+#    #+#             */
/*   Updated: 2022/05/20 16:35:18 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	int				i;
	unsigned char	*p;

	i = 0;
	p = str;
	while (len--)
	{
		*(p + i) = (unsigned char)c;
		i++;
	}
	return (str);
}
