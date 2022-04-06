/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuck <nuck@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:07:56 by nuck              #+#    #+#             */
/*   Updated: 2022/04/06 00:55:51 by nuck             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_case(va_list *args, char ident)
{
	int	i;

	i = 0;
	if (ident == 'c')
		i += ft_putchar(va_arg(*args, int));
	else if (ident == 's')
		i += ft_putstr(va_arg(*args, char *));
	else if (ident == 'i' || ident == 'd')
		i += ft_putbase(va_arg(*args, int), "0123456789");
	else if (ident == 'u')
		i += ft_putbase(va_arg(*args, unsigned int), "0123456789");
	else if (ident == 'x')
		i += ft_putbase(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (ident == 'X')
		i += ft_putbase(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (ident == 'p')
	{
		i += write(1, "0x", 2);
		i += ft_putbase(va_arg(*args, long), "0123456789abcdef");
	}
	else if (ident == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = -1;
	count = 0;
	va_start(args, s);
	while (s[++i] != '\0')
	{
		if (s[i] != '%')
			count += write(1, &s[i], 1);
		else
		{
			count += print_case(&args, s[i + 1]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
