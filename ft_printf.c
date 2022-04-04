/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuck <nuck@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:07:56 by nuck              #+#    #+#             */
/*   Updated: 2022/04/04 23:50:39 by nuck             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_case(va_list *args, char ident)
{
	if (ident == 'c')
		ft_putchar(va_arg(*args, int));
	else if (ident == 's')
		ft_putstr(va_arg(*args, char *));
	else if (ident == '%')
		ft_putchar('%');
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;

	i = -1;
	va_start(args, s);
	while (s[++i] != '\0')
	{
		if (s[i] != '%')
			write(1, &s[i], 1);
		else
		{
			print_case(&args, s[i + 1]);
			i++;
		}
	}
	va_end(args);
	return (0);
}
