/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:45:29 by wcista            #+#    #+#             */
/*   Updated: 2022/07/04 19:03:41 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*dest;
	size_t		i;
	size_t		j;

	i = 0;
	j = start;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	dest = (char *)malloc(len * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	while (j < (start + len))
		dest[i++] = s[j++];
	dest[i] = '\0';
	return (dest);
}
