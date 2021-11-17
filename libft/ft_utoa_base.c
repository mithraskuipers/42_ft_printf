/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkuipers <mkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 17:43:43 by mkuipers      #+#    #+#                 */
/*   Updated: 2021/11/17 22:56:23 by mkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(unsigned int n, int base)
{
	unsigned int	ndigits;
	char			*s;
	char			*base_set;

	base_set = ft_strdup("0123456789abcdef");
	ndigits = ft_ndigits_base(((unsigned int)n), base);
	s = ft_calloc((ndigits + 1), sizeof(char));
	if (!(s))
		return (NULL);
	s[ndigits] = 0;
	while ((ndigits) && (n))
	{
		ndigits--;
		s[ndigits] = base_set[n % base];
		n = n / base;
	}
	return (s);
}
