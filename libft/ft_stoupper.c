/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stoupper.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 10:01:54 by mikuiper      #+#    #+#                 */
/*   Updated: 2021/11/17 10:31:53 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stoupper(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}
