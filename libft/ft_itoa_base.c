/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 10:52:00 by mikuiper      #+#    #+#                 */
/*   Updated: 2021/11/18 18:42:27 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa_base(unsigned long long n, int base)
{
	long long	ndigits;
	char		*s;
	char		*base_set;

	if (n == 0)
		return (ft_strdup("0"));
	ndigits = ft_ndigits_base(((unsigned long long)n), base);
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
