/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:55:25 by wcista            #+#    #+#             */
/*   Updated: 2022/07/26 19:07:36 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkconversions(va_list arg, const char *s, int i)
{
	int	len;

	len = 0;
	if (s[i] == 'c')
		len += ft_putchar(va_arg(arg, int));
	if (s[i] == 's')
		len += ft_putstr(va_arg(arg, char *));
	if (s[i] == 'p')
		len += ft_putpointer(va_arg(arg, char *));
	if (s[i] == 'd')
		len += ft_putnbr(va_arg(arg, int));
	if (s[i] == 'i')
		len += ft_putnbr(va_arg(arg, int));
	if (s[i] == 'u')
		len += ft_putnbr_unsignedint(va_arg(arg, unsigned int));
	if (s[i] == 'x')
		len += ft_putnbr_hexa(va_arg(arg, unsigned int), "0123456789abcdef");
	if (s[i] == 'X')
		len += ft_putnbr_hexa(va_arg(arg, unsigned int), "0123456789ABCDEF");
	if (s[i] == '%')
		len += ft_putstr("%");
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		len;
	size_t	i;

	va_start(arg, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_checkconversions(arg, s, i + 1);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
