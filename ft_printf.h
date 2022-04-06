#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *s);
int		ft_putbase(long long num, char *base);
int		ft_printf(const char *s, ...);
int		print_case(va_list *args, char ident);
int		ft_pointerbase(unsigned long num, char *base);

#endif