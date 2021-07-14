#include "ft_printf.h"

void	ft_putnbr_hex(unsigned long addr)
{
	unsigned long	num;
	unsigned long	rank;
	unsigned long	index;

	num = addr;
	rank = 1;
	while (num > 15)
	{
		num /= 16;
		rank *= 16;
	}
	while (rank > 1)
	{
		index = addr / rank;
		write(1, &"0123456789abcdef"[index], 1);
		addr %= rank;
		rank /= 16;
	}
	write(1, &"0123456789abcdef"[addr], 1);
}

int	ft_min(unsigned long addr, t_flags *flag, int precision, int width)
{
	int	length;

	length = 0;
	if (flag->has_zero && flag->has_dot != 1)
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
	if (addr)
		ft_putnbr_hex(addr);
	else if (flag->has_dot != 1)
		ft_putnbr_hex(addr);
	length += ft_count_hex(addr);
	return (length);
}

int	ft_print_ptr(t_flags *flag, unsigned long addr, int width, int precision)
{
	int	length;

	length = 0;
	if (flag->has_minus != 1)
		length = ft_min(addr, flag, precision, width);
	else
	{
		length += write(1, "0x", 2);
		width -= (precision + 2);
		while (precision-- > ft_count_hex(addr))
			length += write(1, "0", 1);
		if (addr)
			ft_putnbr_hex(addr);
		else if (flag->has_dot != 1)
			ft_putnbr_hex(addr);
		length += ft_count_hex(addr);
		while (width-- > 0)
			length += write(1, &flag->chr, 1);
	}
	return (length);
}

void	ft_i_precision(unsigned long addr, t_flags *flag,
	int *precision, int *width)
{
	if (flag->has_precision < 0)
	{
		flag->has_dot = 0;
		*precision = ft_count_hex(addr);
	}
	else if (flag->has_precision > ft_count_hex(addr))
		*precision = flag->has_precision;
	else if (!addr && flag->has_dot)
		*precision = flag->has_precision;
	else
		*precision = ft_count_hex(addr);
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

int	ft_printf_p(va_list args, t_flags *flag)
{
	unsigned long	addr;
	int				length;
	int				precision;
	int				width;

	addr = va_arg(args, unsigned long);
	if (!addr && flag->has_dot && flag->has_precision == 0 && flag->has_width == 0)
		return ((int)write(1, "0x", 2));
	ft_i_precision(addr, flag, &precision, &width);
	length = ft_print_ptr(flag, addr, width, precision);
	return (length);
}
