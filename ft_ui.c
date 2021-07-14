#include "ft_printf.h"

int	ft_not_minus_ui(unsigned int num, t_flags *flag,
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
	while (precision-- > ft_count(num))
		length += write(1, "0", 1);
	if (num == 0 && flag->has_dot && !flag->has_precision)
		length += write(1, " ", 1);
	else
	{
		length += ft_count(num);
		ft_putnbr_fd(num, 1);
	}
	return (length);
}

int	ft_minus_ui(unsigned int num, t_flags *flag,
		int precision, int width)
{
	int	length;

	length = 0;
	width -= precision;
	while (precision-- > ft_count(num))
		length += write(1, "0", 1);
	if (num == 0 && flag->has_dot && !flag->has_precision)
		length += write(1, " ", 1);
	else
	{
		length += ft_count(num);
		ft_putnbr_fd(num, 1);
	}
	while (width-- > 0)
		length += write(1, &flag->chr, 1);
	return (length);
}

void	ft_i_ui(unsigned int num, t_flags *flag, int *precision, int *width)
{
	if (flag->has_precision < 0)
	{
		flag->has_dot = 0;
		*precision = ft_count(num);
	}
	else if (flag->has_precision > ft_count(num))
		*precision = flag->has_precision;
	else
		*precision = ft_count(num);
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

int 	ft_printf_ui(va_list args, t_flags *flag)
{
	unsigned int	num;
	int				length;
	int				precision;
	int				width;

	length = 0;
	num = va_arg(args, unsigned int);
	if (!num && flag->has_dot && !flag->has_precision && !flag->has_width)
		return (0);
	ft_i_ui(num, flag, &precision, &width);
	if (flag->has_minus != 1)
		length = ft_not_minus_ui(num, flag, precision, width);
	else
		length = ft_minus_ui(num, flag, precision, width);
	return (length);
}
