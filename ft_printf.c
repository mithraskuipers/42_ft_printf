/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/10 10:22:54 by mikuiper      #+#    #+#                 */
/*   Updated: 2021/11/10 17:40:56 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


// cd Documents/repos/personal/codam/ft_printf
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
va_start(ap, last_arg)
ap = va_list object that holds the argument information
last_arg = last_arg − This is the last known fixed argument being passed to the function.

fs = format specifier
*/

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>


/* 
Het eerste argument is een string. Dat is wat bij de reguliere printf() tussen
de dubbele quotes komt. Dat allemaal wordt hier opgevangen in format_list. Wat bij
de reguliere printf() buiten de dubbele quotes komt zijn de argumenten voor printf(),
en dat valt bij mij onder arg_list. Dit betekent dat format_list bij mij 1 deel is
(namelijk 1 string), en arg_list bestaat uit meerdere delen.
*/

int	ft_printf(const char *format_list, ...);
int	print_c(va_list arg);

int	ft_printf(const char *format_list, ...)
{
	//int num;
	va_list arg_list;
	va_start(arg_list, format_list);
	int	i;
	int	j;

	i = 0;
	j = 0;

	char	*tmp;
	format_list_s = (char *)format_list;
	printf("%s", format_list_s);

	//num = va_arg(arg_list, int);
	//printf("%d\n", num);

	va_end(arg_list);

	return (0);
}

int	main(void)
{
	int test1 = 42;
	int test2 = 24;
	ft_printf("Hoi!%n", test1, test2);
	return (0);
}

