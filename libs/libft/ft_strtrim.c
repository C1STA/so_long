/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:30:13 by wcista            #+#    #+#             */
/*   Updated: 2022/07/04 18:11:42 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_trimlen(char const *str, char const *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && ft_isset(set, str[i]))
	{
		count++;
		i++;
	}
	i = ft_strlen(str) - 1;
	while (str[i] && ft_isset(set, str[i]))
	{
		count++;
		i--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*trim;

	i = 0;
	len = ft_strlen(s1) - ft_trimlen(s1, set);
	if (len < 0)
		len = 0;
	trim = (char *)malloc(sizeof(char) * (len + 1));
	if (!trim)
		return (NULL);
	while (s1 && ft_isset(set, s1[i]))
		i++;
	j = 0;
	while (j < len)
		trim[j++] = s1[i++];
	trim[j] = '\0';
	return (trim);
}
