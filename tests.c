#include "ft_printf.h"

void te3t(const char *s, ...)
{
	va_list args;
	int i;

	va_start(args, s);
	i = va_arg(args, int);
	while(i)
	{
		printf("%s %d\n",s,i);
		i = va_arg(args, int);
	}
}

int main()
{
	char *s;

	s = "01234";
	write(1, &s[2], 1);
}