/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:10:30 by wcista            #+#    #+#             */
/*   Updated: 2022/07/26 19:11:04 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_phexa(unsigned long n)
{
	int		len;
	char	*base;

	base = "0123456789abcdef";
	len = 0;
	if (n < 16)
		len += ft_putchar(base[n]);
	if (n >= 16)
	{
		len += ft_putnbr_phexa(n / 16);
		len += ft_putnbr_phexa(n % 16);
	}
	return (len);
}

int	ft_putpointer(void *n)
{
	int				len;
	unsigned long	i;

	len = 0;
	i = (unsigned long)n;
	if (!n)
		return (write(1, "(nil)", 5));
	len += ft_putstr("0x");
	len += ft_putnbr_phexa(i);
	return (len);
}
