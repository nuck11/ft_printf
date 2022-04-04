#include "ft_printf.h"

void	test(const char *s, ...)
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

}