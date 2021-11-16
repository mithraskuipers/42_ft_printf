#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/* struct */

typedef struct s_fs_format
{
	int	fs;
	int	hash;
	int i;
	int	minus;
	int nchars;
	int	period;
	int	plus;
	int precision;
	int	space;
	int	width;
	int	zero;
}	t_fs_format;

/* function: init struct */

void	init_fs_conf(t_fs_format *fs_format)
{
	fs_format = malloc(sizeof(t_fs_format));
	if (!(fs_format))
		return ;

	fs_format->fs = 0;
	fs_format->hash = 0;
	fs_format->minus = 0;
	fs_format->nchars = 0;
	fs_format->period = 0;
	fs_format->plus = 0;
	fs_format->precision = 0;
	fs_format->space = 0;
	fs_format->width = 0;
	fs_format->zero = 0;
}

int		ft_printf(const char *fs_list, ...)
{
	va_list		arg_list;
	int			nchars;
	t_fs_format	*fs_format;

	va_start(arg_list, fs_list);
	nchars = 0;
	while (*fs_list)
	{
		while ((*fs_list) && (*fs_list != '%'))
		{
			write(1, &(*fs_list), 1);
			fs_list++;
			
		}
		if (*fs_list)
		{
			init_fs_conf(fs_format);
		}
		fs_list++;
	}
	va_end(arg_list);
	return (nchars);
}

void main(void)
{
	int a = 10;
	ft_printf("hey %d", a);
	return ;
}