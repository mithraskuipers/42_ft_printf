/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 10:52:00 by mikuiper      #+#    #+#                 */
/*   Updated: 2021/11/17 19:53:22 by mkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long n, int base)
{
	size_t		ndigits;
	char		*s;
	char		*base_set;

	base_set = ft_strdup("0123456789abcdef");
	ndigits = ft_ndigits_base(n, base);
	s = ft_calloc((ndigits + 1), sizeof(char));
	if (!(s))
		return (NULL);
	s[ndigits] = 0;
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	while ((ndigits) && (n))
	{
		ndigits--;
		s[ndigits] = base_set[n % base];
		n = n / base;
	}
	return (s);
}
