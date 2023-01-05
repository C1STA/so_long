/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsignedint.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:06:54 by wcista            #+#    #+#             */
/*   Updated: 2022/10/04 16:56:01 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsignedint(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
	{
		len += ft_putnbr_unsignedint(n / 10);
		len += ft_putnbr_unsignedint(n % 10);
	}
	else
		len += ft_putchar (n + '0');
	return (len);
}
