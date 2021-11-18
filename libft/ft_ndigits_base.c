/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ndigits_base.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 12:02:25 by mikuiper      #+#    #+#                 */
/*   Updated: 2021/11/18 14:54:06 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ndigits_base(long long n, int base)
{
	size_t	ndigits;

	ndigits = 0;
	if (n <= 0)
		ndigits = 1;
	while (n)
	{
		ndigits++;
		n = n / base;
	}
	return (ndigits);
}
