#include "ft_printf.h"

void print_SpecCase(va_list *args, char ident)
{
    if (ident == 'c')
        write(1, &va_arg(args, int), 1);
}

int ft_printf(const char *s, ...)
{
    int i;
    va_list args;

    i = -1;
    va_start(args, s);
    while (s[++i] == '\0')
    {
        if (s[i] != '%')
            write(1, &s[i], 1);
        else
        {
            print_SpecCase(args, s[i + 1]);
            i++;
        }
    }
    return 0;
}

int main()
{
    ft_printf("imprimir %c e isto ",'a', 'z');
}
