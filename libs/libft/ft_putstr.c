/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:02:44 by wcista            #+#    #+#             */
/*   Updated: 2022/07/26 19:03:18 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;

	if (s == NULL)
		return (write(1, "(null)", 6));
	len = 0;
	while (s[len])
		ft_putchar(s[len++]);
	return (len);
}
