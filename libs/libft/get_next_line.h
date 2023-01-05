/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:43:48 by wcista            #+#    #+#             */
/*   Updated: 2023/01/04 11:34:47 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_reader(int fd, char *buffer);
int		ft_isback_n(char *str);
char	*ft_strjoin_after_n(char *buffer);
char	*ft_strjoin_n(char *s1);
char	*ft_ret(char *buffer, char *dest, int k);
void	ft_free_str(char **str);

#endif