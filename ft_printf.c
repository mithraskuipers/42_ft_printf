/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/10 10:22:54 by mikuiper      #+#    #+#                 */
/*   Updated: 2021/11/11 12:08:35 by mikuiper      ########   odam.nl         */
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
de dubbele quotes komt. Dat allemaal wordt hier opgevangen in fs_list. Wat bij
de reguliere printf() buiten de dubbele quotes komt zijn de argumenten voor printf(),
en dat valt bij mij onder arg_list. Dit betekent dat fs_list bij mij 1 deel is
(namelijk 1 string), en arg_list bestaat uit meerdere delen.
*/


/* libft */

void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

void	ft_putstr_fd(char *s, int fd)
{
	write (fd, s, ft_strlen(s));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}





int	ft_printf(const char *fs_list, ...);
int	parse_fs_list(char fs_char, va_list arg_list);


void	ft_putstr_fd(char *str, int fd)
{
	if (str)
		while (*str)
		{
			write(fd, str, 1);
			str++;
		}
}


int		fs_c(vs_list arg_list)
{
	int	arg;

	arg = va_arg(arg_list, int);
	write (1, &arg, 1);
	return (1);
}

int	fs_s(vs_list arg_list)
{
	char	arg
}

int	fs_p(vs_list arg_list)
{
	
}

int	fs_d(vs_list arg_list)
{

}

int	fs_i(vs_list arg_list)
{
	
}

int	fs_u(vs_list arg_list)
{
	
}

int	fs_x(vs_list arg_list)
{

}

int	fs_X(vs_list arg_list)
{
	
}

int	parse_fs_list(char fs_char, va_list arg_list)
{
	int	nchars;

	nchars = 0;
	if (fs_char == 'c')
		nchars = (nchars + fs_c(arg_list));
	if (fs_char == 's')
		nchars = (nchars + fs_s(arg_list));
	if (fs_char == 'p')
		nchars = (nchars + fs_p(arg_list));
	if (fs_char == 'd')
		nchars = (nchars + fs_d(arg_list));
	if (fs_char == 'i')
		nchars = (nchars + fs_i(arg_list));
	if (fs_char == 'u')
		nchars = (nchars + fs_u(arg_list));
	if (fs_char == 'x')
		nchars = (nchars + fs_x(arg_list));
	if (fs_char == 'X')
		nchars = (nchars + fs_X(arg_list));
	if (fs_char == '%')
		write(1, '%%', 1);
}

int	ft_printf(const char *fs_list, ...)
{
	va_list	arg_list;
	char	*fs_list_s;
	int		i;
	int		nchars;

	va_start(arg_list, fs_list);
	i = 0;
	nchars = 0;
	fs_list_s = (char *)fs_list;
	while (fs_list_s[i])
	{
		if (fs_list_s[i] == '%')
		{
			i++;
			parse_fs_list(fs_list_s[i], arg_list);								// wat moet die returnen?
			nchars = nchars + 1;
		}
		else
		{
			nchars = (nchars + write(1, fs_list_s[i], 1));
		}
		i++;
	}
	va_end(arg_list)
	return (nchars);
}

int	main(void)
{
	int test1 = 42;
	int test2 = 24;
	ft_printf("Hoi!   %s", test1, test2);
	return (0);
}

