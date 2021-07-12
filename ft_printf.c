#include "ft_printf.h"

void	ft_init_flags(t_flags *flags)
{
	flags->has_minus = 0;
	flags->has_zero = 0;
	flags->has_width = 0;
	flags->has_dot = 0;
	flags->has_precision = 0;
	flags->chr = ' ';
	flags->hex = 'x';
}

void	ft_define_flag(char **arr, va_list args, t_flags *flag)
{
	while (!ft_isalpha(**arr) && ft_strchr("0123456789.*%-", **arr))
	{
		if (**arr == '-')
			flag->has_minus = 1;
		else if (**arr == '.')
			flag->has_dot = 1;
		else if (**arr == '0' && (*(*arr - 1) == '%' || *(*arr - 1) == '-'))
			flag->has_zero = 1;
		else if (ft_isdigit(**arr) && !(flag->has_dot))
			flag->has_width = (flag->has_width * 10) + (**arr - '0');
		else if (**arr == '*' && !(flag->has_dot))
			flag->has_width = va_arg(args, int);
		else if (ft_isdigit(**arr) && flag->has_dot)
			flag->has_precision = (flag->has_precision * 10) + (**arr - '0');
		else if (**arr == '*' && (flag->has_dot))
			flag->has_precision = va_arg(args, int);
		else if (**arr == '%')
			break ;
		(*arr)++;
	}
}

int	ft_print_smth(char **arr, va_list args, t_flags *flag)
{
	int	num;

	num = 0;
	if (**arr == 'c' || **arr == '%')
		num = ft_printf_c(args, flag, arr);
	else if (**arr == 's')
		num = ft_printf_s(args, flag);
	else if (**arr == 'p')
		num = ft_printf_p(args, flag);
	else if (**arr == 'd' || **arr == 'i')
		num = ft_printf_dig(args, flag);
	else if (**arr == 'u')
		num = ft_printf_ui(args, flag);
	else if (**arr == 'x' || **arr == 'X')
		num = ft_printf_hex(args, flag, arr);
	(*arr)++;
	return (num);
}

int	ft_read_flags(va_list args, char **arr)
{
	t_flags	flags;
	int		num;

	ft_init_flags(&flags);
	ft_define_flag(arr, args, &flags);
	num = ft_print_smth(arr, args, &flags);
	return (num);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	char			*arr;
	int				count;

	count = 0;
	arr = (char *)format;
	va_start(args, format);
	while (*arr)
	{
		if (*arr == '%')
		{
			arr++;
			count += ft_read_flags(args, &arr);
		}
		else
		{
			write(1, arr++, 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
