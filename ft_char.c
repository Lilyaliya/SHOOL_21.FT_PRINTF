#include "ft_printf.h"

int	ft_print(t_flags *flag, char c, int width)
{
	int	length;

	length = 0;
	if (flag->has_minus != 1)
	{
		if (flag->has_zero)
			flag->chr = '0';
		while (width-- > 1)
			length += write(1, &flag->chr, 1);
		length += write(1, &c, 1);
	}
	else
	{
		length += write(1, &c, 1);
		while (width-- > 1)
			length += write(1, " ", 1);
	}
	return (length);
}

int	ft_printf_c(va_list args, t_flags *flag, char **arr)
{
	int		length;
	int		width;
	char	c;

	if (**arr == '%')
		c = '%';
	else
		c = va_arg(args, int);
	width = 1;
	if (flag->has_width < 0)
	{
		flag->has_minus = 1;
		flag->has_width *= (-1);
		width = flag->has_width;
	}
	else if (flag->has_width > 1)
		width = flag->has_width;
	length = ft_print(flag, c, width);
	return (length);
}
