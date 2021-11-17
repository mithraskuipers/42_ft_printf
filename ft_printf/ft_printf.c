/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/10 10:22:54 by mikuiper      #+#    #+#                 */
/*   Updated: 2021/11/17 22:54:26 by mkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* 
Het eerste argument is een string. Dat is wat bij de reguliere printf() tussen
de dubbele quotes komt. Dat allemaal wordt hier opgevangen in fs_list. Wat bij
de reguliere printf() buiten de dubbele quotes komt zijn de argumenten voor printf(),
en dat valt bij mij onder arg_list. Dit betekent dat fs_list bij mij 1 deel is
(namelijk 1 string), en arg_list bestaat uit meerdere delen.
*/

/* libft include */

/*
#include "./libft/ft_ndigits.c"
#include "./libft/ft_calloc2.c"
#include "./libft/ft_putchar_fd.c"
#include "./libft/ft_putnbr_fd.c"
#include "./libft/ft_strdup.c"
#include "./libft/ft_strlen.c"
#include "./libft/ft_utoa.c"
#include "./libft/ft_putstr_fd.c"
#include "./libft/ft_itoa_base.c"
#include "./libft/ft_ndigits_base.c"
#include "./libft/ft_stoupper.c"
#include "./libft/ft_toupper.c"
*/

/* libft end */

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

int	ft_printf(const char *fs_list, ...);
int	parse_fs_list(char fs_char, va_list arg_list);

int fs_c(va_list arg_list);
int fs_s(va_list arg_list);
int fs_p(va_list arg_list);
int fs_d(va_list arg_list);
int fs_i(va_list arg_list);
int fs_u(va_list arg_list);
int fs_x(va_list arg_list);
int fs_X(va_list arg_list);

int	fs_c(va_list arg_list)
{
	int	arg;

	arg = va_arg(arg_list, int);
	write (1, &arg, 1);
	return (1);
}

int	fs_s(va_list arg_list)
{
	char	*arg;

	arg = va_arg(arg_list, char *);

	if (!(arg))
	{
		write (1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(arg, 1);
	return (ft_strlen(arg));
}

int	fs_di(va_list arg_list)
{
	char	*s;
	int		arg;

	arg = va_arg(arg_list, int);
	s = ft_itoa_base(arg, 10);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	fs_u(va_list arg_list)
{
	unsigned int	arg;
	char			*s;

	arg = va_arg(arg_list, unsigned int);
	s = ft_utoa_base(arg, 10);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	fs_x(va_list arg_list)
{
	char	*s;
	unsigned int		arg;

	arg = ((unsigned int)va_arg(arg_list, int));
	s = ft_itoa_base(arg, 16);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	fs_X(va_list arg_list)
{
	char	*s;
	unsigned int		arg;

	arg = ((unsigned int)va_arg(arg_list, int));
	s = ft_itoa_base(arg, 16);
	s = ft_stoupper(s);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	fs_p(va_list arg_list)
{
	char	*s;
	void	*arg;
	int		write_len;

	arg = va_arg(arg_list, void *);
	s = ft_itoa_base((long long)arg, 16);
	write_len = write(1, "0x", 2);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s) + write_len);
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
	if ((fs_char == 'd') || (fs_char == 'i'))
		nchars = (nchars + fs_di(arg_list));
	if (fs_char == 'u')
		nchars = (nchars + fs_u(arg_list));
	if (fs_char == 'x')
		nchars = (nchars + fs_x(arg_list));
	if (fs_char == 'X')
		nchars = (nchars + fs_X(arg_list));
	if (fs_char == '%')
		write(1, "%%", 1);
	return (nchars);
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
			nchars = nchars + parse_fs_list(fs_list_s[i], arg_list);
		}
		else
		{
			nchars = nchars + write(1, &fs_list_s[i], 1);
		}
		i++;
	}
	va_end(arg_list);
	return (nchars);
}


/*
int	main(void)
{
	char c_test1 = 'A'; 														// 1
	char c_test2 = '9'; 														// 1
	char s_test1[] = "Goodmorning"; 											// 11
	char s_test2[] = "wower43s4t3y794t3"; 										// 17
	int i_test1 = 123;															// 3
	int i_test2 = 9876543211111;													// 9
	unsigned int u_test1 = 123;													// 3
	unsigned int u_test2 = 0;													// 10 // 4294967295
	unsigned int x_test1 = 123;															// 3
	unsigned int x_test2 = 747824379242479212121111;
	unsigned int X_test1 = 123;															// 3
	unsigned int X_test2 = 747824379242479212121111;
	unsigned int *p_test1 = x_test1;											// 3
	unsigned int *p_test2 = x_test2;

	int c_count_own;
	int c_count_old;
	printf("\nargument --> c \n");
	c_count_own = ft_printf("%c %c\n", c_test1, c_test2);
	c_count_old = printf("%c %c\n", c_test1, c_test2);
	printf("Own: %d\n", c_count_own);
	printf("Old: %d\n", c_count_old);

	int s_count_own;
	int s_count_old;
	printf("\nargument --> s \n");
	s_count_own = ft_printf("%s %s\n", s_test1, s_test2);
	s_count_old = printf("%s %s\n", s_test1, s_test2);
	printf("Own: %d\n", s_count_own);
	printf("Old: %d\n", s_count_old);

	int i_count_own;
	int i_count_old;
	printf("\nargument --> i \n");
	i_count_own = ft_printf("%i %i\n", i_test1, i_test2);
	i_count_old = printf("%i %i\n", i_test1, i_test2);
	printf("Own: %d\n", i_count_own);
	printf("Old: %d\n", i_count_old);

	int u_count_own;
	int u_count_old;
	printf("\nargument --> u \n");
	u_count_own = ft_printf("%u %u\n", u_test1, u_test2);
	u_count_old = printf("%u %u\n", u_test1, u_test2);
	printf("Own: %d\n", u_count_own);
	printf("Old: %d\n", u_count_old);
	
	int x_count_own;
	int x_count_old;
	printf("\nargument --> x \n");
	x_count_own = ft_printf("%x %x\n", x_test1, x_test2);
	x_count_old = printf("%x %x\n", x_test1, x_test2);
	printf("Own: %d\n", x_count_own);
	printf("Old: %d\n", x_count_old);
	
	int X_count_own;
	int X_count_old;
	printf("\nargument --> X \n");
	X_count_own = ft_printf("%X %X\n", X_test1, X_test2);
	X_count_old = printf("%X %X\n", X_test1, X_test2);
	printf("Own: %d\n", X_count_own);
	printf("Old: %d\n", X_count_old);

	int p_count_own;
	int p_count_old;
	printf("\nargument --> p \n");
	p_count_own = ft_printf("%p %p\n", p_test1, p_test2);
	p_count_old = printf("%p %p\n", p_test1, p_test2);
	printf("Own: %d\n", p_count_own);
	printf("Old: %d\n", p_count_old);

	printf("\n=======================\n");
}
*/