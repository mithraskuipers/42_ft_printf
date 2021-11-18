#include <stdio.h>
#include "./ft_printf/ft_printf.h"

int	main(void)
{
	int	a;
	a = 822389;
	int *b;
	b = &a;
	ft_printf("ft_printf(): This %p is even stranger", (void *)-1);
	printf("\n");
	printf("printf(): This %p is even stranger", (void *)-1);

	return (0);
}

/*
gcc main.c libftprintf.a && ./a.out
*/