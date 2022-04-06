/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuck <nuck@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:19:46 by nuck              #+#    #+#             */
/*   Updated: 2022/04/06 14:10:26 by nuck             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putbase(long long num, char *base)
{
	long long	max;
	int			i;

	i = 0;
	max = (long long)ft_strlen(base);
	if (num < 0)
	{
		num *= -1;
		i += write(1, "-", 1);
	}
	if (num < max)
	{
		i += write(1, &base[num], 1);
		return (i);
	}
	i += ft_putbase(num / max, base);
	i += write(1, &base[num % max], 1);
	return (i);
}

int	ft_pointerbase(unsigned long num, char *base)
{
	unsigned long	max;
	int				i;

	i = 0;
	max = (unsigned long)ft_strlen(base);
	if (num < max)
	{
		i += write(1, &base[num], 1);
		return (i);
	}
	i += ft_pointerbase(num / max, base);
	i += write(1, &base[num % max], 1);
	return (i);
}
