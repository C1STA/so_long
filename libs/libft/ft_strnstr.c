/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:40:17 by wcista            #+#    #+#             */
/*   Updated: 2022/06/25 21:13:57 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*to_find == '\0' || to_find == NULL)
		return ((char *) str);
	while (str[i] != '\0' && i < size)
	{
		j = 0;
		while (to_find[j] == str[i + j] && i + j < size)
		{
			if (to_find[j + 1] == '\0')
				return ((char *) str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
