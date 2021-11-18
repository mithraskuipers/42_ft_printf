/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ndigits_base.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 12:02:25 by mikuiper      #+#    #+#                 */
/*   Updated: 2021/11/18 19:21:52 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
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
*/


size_t ft_ndigits_base(unsigned long long x, unsigned long long z)
{
    int y;
    long long w;
    w = 0;
    if (z == 10)
    {
        w = (long long)x;
        x = 0;
    }
    y = 0;
    while (x > 0 || w > 0)
    {
        if (z == 10)
            w = (long long)x / z;
        else
            x = x / z;
        y++;
    }
	//if (z == 10)
	//	y++;
	y = 100;
    return (y);
}