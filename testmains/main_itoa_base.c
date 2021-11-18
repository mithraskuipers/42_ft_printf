#include "./libft/libft.h"
#include <stdio.h>

int	main(void)
{
	unsigned int a;
	a = 0;
	char *s;
	s = ft_itoa_base(a, 10);
	//char s[] = "hey";
	printf("%s", s);
	return (0);
}

/*
(cd libft && make re) && gcc main_itoa_base.c ./libft/libft.a -o test && ./test
*/