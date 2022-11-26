/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:41:29 by wcista            #+#    #+#             */
/*   Updated: 2022/11/24 18:41:51 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

void	ft_free_str(char **str)
{
	if (str != NULL && **str != '\0')
	{
		free(*str);
		*str = NULL;
	}
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	len;
	int		i;
	int		j;

	if ((!s1) && (!s2))
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	len = (i + j + 1);
	dest = malloc((len) * sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		dest[j++] = s1[i];
	i = -1;
	while (s2[++i])
		dest[j++] = s2[i];
	dest[j] = '\0';
	ft_free_str(&s1);
	return (dest);
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
