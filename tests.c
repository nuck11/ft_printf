#include "ft_printf.h"
#include "stdio.h"
#include "stdlib.h"

int main()
{
	char *p;

	p = malloc(20);
	//ft_printf("char: %c, string: %s, int: %i, decimal: %d, unsigned: %u, hexa: %X, pointer: %p",'a',"yay",3,10,14,-500,p);
	printf("\n%d\n",ft_printf("char: %c, string: %s, int: %i, decimal: %d, unsigned: %u, hexa: %X, pointer: %p",'a',"yay",3,10,14,-500,p));
	printf("\n%d\n",printf("char: %c, string: %s, int: %i, decimal: %d, unsigned: %u, hexa: %X, pointer: %p",'a',"yay",3,10,14,-500,p));
}