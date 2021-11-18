/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/10 10:22:54 by mikuiper      #+#    #+#                 */
/*   Updated: 2021/11/18 19:12:35 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

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
	int		len;

	arg = (unsigned long long)va_arg(arg_list, unsigned long long);
	s = ft_itoa_base(arg, 10);
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	free (s);
	return (len);
}

int	fs_u(va_list arg_list)
{
	unsigned int	arg;
	char			*s;
	int				len;

	arg = va_arg(arg_list, unsigned int);
	s = ft_utoa_base(arg, 10);
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	free (s);
	return (len);
}

int	fs_x(va_list arg_list)
{
	char			*s;
	unsigned int	arg;
	int				len;

	arg = ((unsigned int)va_arg(arg_list, int));
	s = ft_itoa_base(arg, 16);
	ft_putstr_fd(s, 1);

	len = ft_strlen(s);
	free (s);
	return (len);
}

int	fs_X(va_list arg_list)
{
	char			*s;
	unsigned int	arg;
	int				len;

	arg = ((unsigned int)va_arg(arg_list, int));
	s = ft_itoa_base(arg, 16);
	s = ft_stoupper(s);
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	free (s);
	return (len);
}


char	*ft_itoa_base2(unsigned long long n, int base)
{
	long long	ndigits;
	char		*s;
	char		*base_set;

	if (n == 0)
		return (ft_strdup("0"));
	ndigits = ft_ndigits_base(((long)n), base);
	//printf("\n%lld\n", ndigits);
	s = ft_calloc((ndigits + 1), sizeof(char));
	base_set = ft_strdup("0123456789abcdef");
	if ((!(base_set)) || (!(s)))
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		n = n * -1;
	}
	s[ndigits] = 0;
	while ((ndigits) && (n))
	{
		ndigits--;
		s[ndigits] = base_set[n % base];
		n = n / base;
	}
	free (base_set);
	return (s);
}


int	fs_p(va_list arg_list)
{
	char				*s;
	unsigned long long 		arg;
	int					len;
	int 				write_len;

	arg = ((unsigned long long)va_arg(arg_list, unsigned long long));


	//printf("before: %llx\n", arg);
	//printf("%s\n", s);
	//ft_printf("%x\n", arg);
	s = ft_itoa_base((unsigned long long)arg, 16);
	//printf("after: %llx\n", arg);
	//printf("s after: %s\n", s);

	write_len = write(1, "0x", 2);

	ft_putstr_fd(s, 1);

	len = ft_strlen(s);
	free (s);
	return (len + write_len);
}

/*
int	fs_p(va_list arg_list)
{
	char	*s;
	void	*arg;
	int		write_len;
	int 	len;
	
	arg = va_arg(arg_list, void *);
	s = ft_itoa_base((unsigned long)arg, 16);
	write_len = write(1, "0x", 2);
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	free (s);
	return (len + write_len);
}
*/

int	parse_format(char fs_char, va_list arg_list)
{
	int	nchars;

	nchars = 0;
	if (fs_char == 'c')
		nchars = (nchars + fs_c(arg_list));
	else if (fs_char == 's')
		nchars = (nchars + fs_s(arg_list));
	else if (fs_char == 'p')
		nchars = (nchars + fs_p(arg_list));
	else if ((fs_char == 'd') || (fs_char == 'i'))
		nchars = (nchars + fs_di(arg_list));
	else if (fs_char == 'u')
		nchars = (nchars + fs_u(arg_list));
	else if (fs_char == 'x')
		nchars = (nchars + fs_x(arg_list));
	else if (fs_char == 'X')
		nchars = (nchars + fs_X(arg_list));
	else if (fs_char == '%')
		nchars = (nchars + write(1, "%", 1));
	return (nchars);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_list;
	char	*format_s;
	int		i;
	int		nchars;

	va_start(arg_list, format);
	i = 0;
	nchars = 0;
	format_s = (char *)format;
	while (format_s[i])
	{
		if (format_s[i] == '%')
		{
			i++;
			nchars = (nchars + parse_format(format_s[i], arg_list));
		}
		else
		{
			nchars = (nchars + write(1, &format_s[i], 1));
		}
		i++;
	}
	va_end(arg_list);
	return (nchars);
}
