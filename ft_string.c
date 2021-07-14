#include "ft_printf.h"

void	ft_precision(char *str, t_flags *flag, int *precision, int *width)
{
	*precision = ft_strlen(str);
	if (flag->has_precision > (int)ft_strlen(str))
		*precision = ft_strlen(str);
	else if (flag->has_precision < (int)ft_strlen(str) && flag->has_dot)
		*precision = flag->has_precision;
	if (flag->has_precision < 0 || flag->has_width < 0)
	{
		flag->has_minus = 1;
		if (flag->has_precision < 0)
		{
			flag->has_precision = 0;
			*precision = ft_strlen(str);
		}
		if (flag->has_width < 0)
			flag->has_width *= (-1);
	}
	if (flag->has_width > *precision)
		*width = flag->has_width;
	else
		*width = *precision;
	if (*width < 0)
		*width *= (-1);
}

int	ft_print_str(t_flags *flag, char *str, int precision, int width)
{
	int	length;

	length = 0;
	if (flag->has_minus != 1)
	{
		if (flag->has_zero)
			flag->chr = '0';
		while (width-- > precision)
			length += write(1, &flag->chr, 1);
		while (precision--)
			length += write(1, str++, 1);
	}
	else
	{
		width -= precision;
		while (precision--)
			length += write(1, str++, 1);
		while (width--)
			length += write(1, &flag->chr, 1);
	}
	return (length);
}

int	ft_printf_s(va_list args, t_flags *flag)
{
	int		length;
	char	*str;
	int		precision;
	int		width;

	str = va_arg(args, char *);
	length = 0;
	if (str == NULL)
		str = "(null)";
	ft_precision(str, flag, &precision, &width);
	length = ft_print_str(flag, str, precision, width);
	return (length);
}
