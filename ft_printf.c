/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/10 10:22:54 by mikuiper      #+#    #+#                 */
/*   Updated: 2021/11/14 15:31:00 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


/*
cd Documents/repos/personal/codam/ft_printf
/home/mkuipers/Documents/ft_printf
gcc ft_printf.c && ./a.out Hey
*/

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


/* libft start */

size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

static int	ft_ndigits(long n);
static char	*ft_strfiller(char *n_str, int ndigits, long n_long);
char	*ft_itoa(int n);

// PUTSTR

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	write (fd, s, ft_strlen(s));
}

// STRDUP

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!(dup))
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// PUTNBR

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = n * -1;
	}
	else
		nbr = n;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
}

// ITOA

static int	ft_ndigits(long n)
{
	int	ndigits;

	ndigits = 0;
	if (n < 0)
	{
		ndigits++;
		n = n * -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		ndigits++;
	}
	return (ndigits);
}

static char	*ft_strfiller(char *n_str, int ndigits, long n_long)
{
	n_str[ndigits] = '\0';
	ndigits--;
	if (n_long < 0)
	{
		n_str[0] = '-';
		n_long = n_long * -1;
	}
	if (n_long == 0)
	{
		n_str[0] = '0';
		return (n_str);
	}
	while (n_long > 0)
	{
		n_str[ndigits] = (n_long % 10) + '0';
		n_long = n_long / 10;
		ndigits--;
	}
	return (n_str);
}

char	*ft_itoa(int n)
{
	char	*n_str;
	int		ndigits;
	long	n_long;

	n_long = (long)n;
	ndigits = ft_ndigits(n_long);
	n_str = malloc(sizeof(char) * (ndigits + 1));
	if (!(n_str))
		return (NULL);
	return (ft_strfiller(n_str, ndigits, n_long));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!(ptr))
		return (NULL);
	//ft_memset(ptr, 0, count * size);
	//ft_bzero(ptr, count * size);
	size_t			i;
	size_t			len;
	unsigned char	*b_uc;
	unsigned char c;
	c = 0;
	len = count * size;
	i = 0;
	b_uc = (unsigned char *)ptr;
	while (i < len)
	{
		b_uc[i] = c;
		i++;
	}
	return (ptr);
}











char	*ft_utoa(unsigned int n)
{
	char			*n_str;
	unsigned int	ndigits;

	if (n == 0)
		return (ft_strdup("0"));
	ndigits = ft_ndigits(n);
	n_str = ft_calloc(sizeof(char), (ndigits + 1));
	if (!(n_str))
		return (NULL);
	ndigits--;
	if (n < 0)
	{
		n_str[0] = '-';
		n = n * -1;
	}
	if (n == 0)
		return (n_str);
	while (n > 0)
	{
		n_str[ndigits] = (n % 10) + '0';
		n = n / 10;
		ndigits--;
	}
	return (n_str);
}

/* libft end */

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

int		fs_c(va_list arg_list)
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

int	fs_p(va_list arg_list)
{
	return (0);
}

int	fs_di(va_list arg_list)
{
	char	*arg;
	char	*s;

	arg = va_arg(arg_list, int);
	s = ft_itoa(arg);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

// %u print an unsigned decimal (base 10) number.

int	fs_u(va_list arg_list)
{
	char	*arg;
	char	*s;

	arg = va_arg(arg_list, unsigned int);
	s = ft_utoa(arg);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	fs_x(va_list arg_list)
{
	return (0);
}

int	fs_X(va_list arg_list)
{
	return (0);
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
	//printf("\n%d", i_test1);
	printf("\n=======================\n");

	int u_count;
	u_count = ft_printf("%u %u", u_test1, u_test2); 							// 11 + 17 + 1
	printf("\n");
	u_count = printf("%u %u", u_test1, u_test2); 							// 11 + 17 + 1
	printf("\n");

	printf("Number of chars: %d", u_count);
	//printf("\n%d", u_test1);
	printf("\n=======================\n");




	return (0);
}