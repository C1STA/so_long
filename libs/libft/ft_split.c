/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 05:03:06 by wcista            #+#    #+#             */
/*   Updated: 2022/07/07 14:20:47 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_word(const char *s, char c)
{
	int		i;
	char	*wd;

	i = 0;
	while (*s && *s == c)
		s++;
	while (s[i] && s[i] != c)
		i++;
	wd = malloc(sizeof(char) * (i + 1));
	if (wd == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		wd[i] = s[i];
		i++;
	}
	wd[i] = '\0';
	return (wd);
}

static void	ft_free(int i, char **ptr)
{
	while (i > 0)
	{
		free(ptr[i - 1]);
		i--;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**p_words;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	p_words = malloc(sizeof(char *) * (words + 1));
	if (p_words == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		p_words[i] = ft_word(s, c);
		if (p_words[i] == NULL)
			ft_free(i, p_words);
		while (*s && *s != c)
			s++;
		i++;
	}
	p_words[i] = NULL;
	return (p_words);
}
