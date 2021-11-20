/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pointer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/19 15:27:57 by mikuiper      #+#    #+#                 */
/*   Updated: 2021/11/19 15:28:13 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	fs_p(va_list arg_list)
{
	char				*s;
	unsigned long long	arg;
	int					len;
	int					write_len;

	arg = ((unsigned long long)va_arg(arg_list, unsigned long long));
	s = ft_utoa_base((unsigned long long)arg, 16);
	write_len = write(1, "0x", 2);
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	free (s);
	return (len + write_len);
}
