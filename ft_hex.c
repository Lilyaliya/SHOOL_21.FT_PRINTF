#include "ft_printf.h"

int	ft_not_minus_hex(unsigned int num, t_flags *flag,
		int precision, int width)
{
	int	length;

	length = 0;
	while (width-- > precision)
	{
		if (flag->has_zero && !flag->has_dot)
			flag->chr = '0';
		length += write(1, &flag->chr, 1);
	}
	while (precision-- > ft_count_hex(num))
		length += write(1, "0", 1);
	if (!num && flag->has_dot && flag->has_precision)
		length += write(1, " ", 1);
	else
	{
		ft_putnbr_hex_Xx(num, flag);
		length += ft_count_hex(num);
	}
	return (length);
}

int	ft_minus_hex(unsigned int num, t_flags *flag, int precision, int width)
{
	int	length;

	length = 0;
	width -= precision;
	while (precision-- > ft_count_hex(num))
		length += write(1, "0", 1);
	if (!num && flag->has_dot && !flag->has_precision)
		length += write(1, " ", 1);
	else
	{
		ft_putnbr_hex_Xx(num, flag);
		length += ft_count_hex(num);
	}
	while (width-- > 0)
		length += write(1, &flag->chr, 1);
	return (length);
}

void	ft_i_hex(unsigned int num, t_flags *flag, int *precision, int *width)
{
	if (flag->has_precision < 0)
	{
		flag->has_dot = 0;
		*precision = ft_count_hex(num);
	}
	if (flag->has_precision > ft_count_hex(num))
		*precision = flag->has_precision;
	else
		*precision = ft_count_hex(num);
	if (flag->has_width < 0)
	{
		flag->has_minus = 1;
		flag->has_width *= (-1);
	}
	if (flag->has_width > *precision)
		*width = flag->has_width;
	else
		*width = *precision;
}

int	ft_printf_hex(va_list args, t_flags *flag, char **arr)
{
	unsigned int	num;
	int				res;
	int				precision;
	int				width;

	num = va_arg(args, int);
	if (!num && flag->has_dot && !flag->has_precision && !flag->has_width)
		return (0);
	if (**arr == 'X')
		flag->hex = 'X';
	ft_i_hex(num, flag, &precision, &width);
	if (flag->has_minus != 1)
		res = ft_not_minus_hex(num, flag, precision, width);
	else
		res = ft_minus_hex(num, flag, precision, width);
	return (res);
}
