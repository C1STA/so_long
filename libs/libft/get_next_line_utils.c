/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:41:29 by wcista            #+#    #+#             */
/*   Updated: 2023/01/04 11:31:36 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free_str(char **str)
{
	if (str != NULL && **str != '\0')
	{
		free(*str);
		*str = NULL;
	}
}

char	*ft_ret(char *buffer, char *dest, int k)
{
	int	i;

	i = 0;
	k++;
	while (buffer[k])
		dest[i++] = buffer[k++];
	dest[i] = '\0';
	free(buffer);
	return (dest);
}

char	*ft_strjoin_n(char *s1)
{
	char	*dest;
	int		i;
	int		j;
	int		k;

	k = 0;
	if (!(s1))
		return (NULL);
	while (s1[k] != '\n' && s1[k])
		k++;
	dest = malloc(sizeof(char) * k + 2);
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && i <= k)
	{
		dest[i] = s1[j];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
