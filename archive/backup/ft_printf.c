int	ft_printf(const char *fs_list, ...)
{
	va_list	arg_list;
	char	*fs_list_s;
	int		i;
	int		nchars;

	va_start(arg_list, fs_list);
	i = 0;
	nchars = 0;
	fs_list_s = (char *)fs_list;
	while (fs_list_s[i])
	{
		if (fs_list_s[i] == '%')
		{
			i++;
			nchars = nchars + parse_fs_list(fs_list_s[i], arg_list);
		}
		else
		{
			nchars = nchars + write(1, &fs_list_s[i], 1);
		}
		i++;
	}
	va_end(arg_list);
	return (nchars);
}