/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 11:59:54 by mikuiper      #+#    #+#                 */
/*   Updated: 2021/11/18 12:12:21 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
#include <stdarg.h>


int	ft_printf(const char *fs_list, ...);
int	parse_fs_list(char fs_char, va_list arg_list);

int fs_c(va_list arg_list);
int fs_s(va_list arg_list);
int fs_p(va_list arg_list);
int fs_d(va_list arg_list);
int fs_i(va_list arg_list);
int fs_u(va_list arg_list);
int fs_x(va_list arg_list);
int fs_X(va_list arg_list);