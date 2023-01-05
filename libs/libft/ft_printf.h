/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:14:42 by wcista            #+#    #+#             */
/*   Updated: 2022/07/26 19:18:51 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_checkconversions(va_list arg, const char *s, int i);
int	ft_printf(const char *s, ...);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putnbr_unsignedint(unsigned int n);
int	ft_putnbr_hexa(unsigned int n, char *base);
int	ft_putpointer(void *n);

#endif