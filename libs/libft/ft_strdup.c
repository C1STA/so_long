/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:01:05 by wcista            #+#    #+#             */
/*   Updated: 2022/06/24 13:28:08 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		nitems;
	int		i;

	i = 0;
	nitems = (int) ft_strlen(src) + 1;
	dup = malloc(nitems * sizeof(char));
	if (dup == NULL)
		return (dup);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
