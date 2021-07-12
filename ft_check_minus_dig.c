#include "ft_printf.h"

int 	ft_not_minus_p(t_flags *flag, long long num, int precision, int width)
{
	int		lenght;

	lenght = 0;
	if (flag->has_zero && !flag->has_dot)
		flag->chr = '0';
	while (width-- > precision)
		lenght += write(1, &flag->chr, 1);
	while (precision-- > ft_count(num))
		lenght += write(1, "0", 1);
	if (num == 0 && flag->has_dot && !flag->has_precision)
		lenght += write(1, " ", 1);
	else
	{
		lenght += ft_count(num);
		ft_putnbr_fd(num, 1);
	}
	return (lenght);
}

int	ft_minus_p(t_flags *flag, long long num, int precision, int width)
{
	int		length;

	length = 0;
	width -= precision;
	while (precision-- > ft_count(num))
		length += write(1, "0", 1);
	if (num == 0 && flag->has_dot && flag->has_precision == 0)
		length += write(1, " ", 1);
	else
	{
		length += ft_count(num);
		ft_putnbr_fd(num, 1);
	}
	while (width--)
		length += write(1, " ", 1);
	return (length);
}

int	ft_not_minus_n(t_flags *flag, long long num, int precision, int width)
{
	int	length;

	length = 0;
	if (flag->has_zero && !flag->has_dot)
		flag->chr = '0';
	if (flag->chr == '0')
		length += write(1, "-", 1);
	while (width-- > (precision + 1))
		length += write(1, &flag->chr, 1);
	if (flag->chr == ' ')
		length += write(1, "-", 1);
	while (precision-- > ft_count(num))
		length += write(1, "0", 1);
	ft_putnbr_fd(num, 1);
	length += ft_count(num);
	return (length);
}

int	ft_minus_n(t_flags *flag, long long num, int precision, int width)
{
	int		length;

	length = 0;
	width -= (precision + 1);
	length += write(1, "-", 1);
	while (precision-- > ft_count(num))
		length += write(1, "0", 1);
	ft_putnbr_fd(num, 1);
	length += ft_count(num);
	while (width-- > 0)
		length += write(1, &flag->chr, 1);
	return (length);
}

int	ft_min(unsigned long addr, t_flags *flag, int precision, int width)
{
	int	length;

	length = 0;
	if (flag->has_zero && !flag->has_dot)
	{
		flag->chr = '0';
		length += write(1, "0x", 2);
	}
	while (width-- > (precision + 2))
		length += write(1, &flag->chr, 1);
	if (flag->chr == ' ')
		length += write(1, "0x", 2);
	while (precision-- > ft_count_hex(addr))
		length += write(1, "0", 1);
	if (!flag->has_dot)
		ft_putnbr_hex(addr);
	else if (addr)
		ft_putnbr_hex(addr);
	length += ft_count_hex(addr);
	return (length);
}
