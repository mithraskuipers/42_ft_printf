/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fs_c.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/19 15:32:39 by mikuiper      #+#    #+#                 */
/*   Updated: 2021/11/19 15:57:16 by mikuiper      ########   odam.nl         */
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
