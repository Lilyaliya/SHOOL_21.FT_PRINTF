#include "ft_printf.h"

int	ft_count_hex(unsigned long num)
{
	int	i;

	i = 0;
	while (num > 15)
	{
		i++;
		num /= 16;
	}
	return (i + 1);
}

void	ft_putnbr_hex_Xx(unsigned long addr, t_flags *flag)
{
	unsigned long	copy;
	unsigned long	i;
	unsigned long	nb;
	char			*alph;

	copy = addr;
	i = 1;
	alph = "0123456789ABCDEF";
	if (flag->hex == 'x')
		alph = "0123456789abcdef";
	while (copy > 15)
	{
		copy /= 16;
		i *= 16;
	}
	while (i > 0)
	{
		nb = addr / i;
		write(1, &alph[nb], 1);
		addr %= i;
		i /= 16;
	}
}

void 	ft_putnbr_fd(long long n, int fd)
{
	unsigned int	nb;
	unsigned int	na;
	unsigned int	i;

	nb = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	na = n;
	while (na >= 10)
	{
		nb = nb * 10;
		na = na / 10;
	}
	while (nb != 0)
	{
		i = n / nb + 48;
		write(fd, &i, 1);
		n = n % nb;
		nb /= 10;
	}
}

int	ft_strchr(const char *s, int c)
{
	char	*mass;
	int		i;

	if (!s)
		return (0);
	mass = (char *)s;
	i = 0;
	while (mass[i] != '\0')
	{
		if (mass[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}
