#include "./libft/libft.h"
#include <stdio.h>

int	main(void)
{
	unsigned long long a;
	a = 10;
	size_t ndigits;

	ndigits = ft_ndigits_base(a, 10);
	//char s[] = "hey";
	printf("%zu", ndigits);
	return (0);
}

/*
(cd libft && make re) && gcc main_itoa_base.c ./libft/libft.a -o test && ./test
*/