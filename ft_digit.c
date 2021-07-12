#include "ft_printf.h"

int	ft_pos(t_flags *flag, long long num, int precision, int width)
{
	int		length;

	length = 0;
	if (flag->has_minus != 1)
		length += ft_not_minus_p(flag, num, precision, width);
	else
		length += ft_minus_p(flag, num, precision, width);
	return (length);
}

int	ft_neg(t_flags *flag, long long num, int precision, int width)
{
	int		length;

	length = 0;
	num *= (-1);
	if (!flag->has_minus)
		length += ft_not_minus_n(flag, num, precision, width);
	else
		length += ft_minus_n(flag, num, precision, width);
	return (length);
}

void	ft_i_prec(long long num, t_flags *flag, int *precision, int *width)
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
	return ;
}

int	ft_i_flag(t_flags *flag, long long num)
{
	int	precision;
	int	width;
	int	res;

	ft_i_prec(num, flag, &precision, &width);
	if (num >= 0)
		res = ft_pos(flag, num, precision, width);
	else
		res = ft_neg(flag, num, precision, width);
	return (res);
}

int	ft_printf_dig(va_list args, t_flags *flag)
{
	int			length;
	long long	num;

	num = va_arg(args, int);
	if (!num && flag->has_dot && !flag->has_precision && !flag->has_width)
		return (0);
	length = ft_i_flag(flag, num);
	return (length);
}
