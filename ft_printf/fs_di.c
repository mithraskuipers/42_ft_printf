/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fs_di.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/19 15:32:29 by mikuiper      #+#    #+#                 */
/*   Updated: 2021/11/19 15:41:30 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

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
