/*
cspdiuxX%
A small description of the required conversion:
• %c print a single character.
• %s print a string of characters.
• %p The void * pointer argument is printed in hexadecimal.
• %d print a decimal (base 10) number.
• %i print an integer in base 10.
• %u print an unsigned decimal (base 10) number.
• %x print a number in hexadecimal (base 16), with lowercase.
• %X print a number in hexadecimal (base 16), with uppercase.
• %% print a percent sign.
*/

/*
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include "ft_printf.c"

int	main(void)
{
	char c_test1 = 'A'; 														// 1
	char c_test2 = '9'; 														// 1
	char s_test1[] = "Goodmorning"; 											// 11
	char s_test2[] = "wower43s4t3y794t3"; 										// 17
	int i_test1 = 123;															// 3
	int i_test2 = 987654321;													// 9
	unsigned int u_test1 = 123;													// 3
	unsigned int u_test2 = 0;													// 10 // 4294967295

	int c_count;
	c_count = ft_printf("%c %c", c_test1, c_test2); 							// 8
	printf("\n");
	printf("Number of chars: %d", c_count);
	printf("\n=======================\n");

	int s_count;
	s_count = ft_printf("%s %s", s_test1, s_test2); 							// 11 + 17 + 1
	printf("\n");
	printf("Number of chars: %d", s_count);
	printf("\n=======================\n");

	int i_count;
	i_count = ft_printf("%i %i", i_test1, i_test2); 							// 11 + 17 + 1
	printf("\n");
	printf("Number of chars: %d", i_count);
	printf("\n=======================\n");

	int u_count;
	u_count = ft_printf("%u %u", u_test1, u_test2); 							// 11 + 17 + 1
	printf("\n");
	u_count = printf("%u %u", u_test1, u_test2); 								// 11 + 17 + 1
	printf("\n");

	printf("Number of chars: %d", u_count);
	printf("\n=======================\n");
}
*/

#include <stdio.h>
void main(void)
{
	int	a = 100.12345;
	int b = 12345;
	char s[] = "Mithras";

	printf("%.4s is level %10d", s, a);
}

/*
Getal bepaald hoeveel character space er gebruikt moet worden voor die fs.
Geen minus: Ruimte wordt opgevuld met spaties vanaf de linkerkant. %10d
Wel minus: Ruimte wordt opgevuld met spaties vanaf de rechterkant. %-10d
0: Ruimte wordt opgevuld met 0 symbolen, niet met spaties. %010d
*/