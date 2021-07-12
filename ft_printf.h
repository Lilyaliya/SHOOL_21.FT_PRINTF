#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	has_minus;
	int	has_zero;
	int	has_width;
	int	has_dot;
	int	has_precision;
	int	chr;
	int	hex;
}				t_flags;

int		ft_count_hex(unsigned long num);

void	ft_putnbr_hex_Xx(unsigned long addr, t_flags *flag);

void	ft_putnbr_fd(long long n, int fd);

void	ft_putnbr_hex(unsigned long addr);

void	ft_init_flags(t_flags *flags);

int		ft_isalpha(int c);

int		ft_isdigit(int c);

size_t	ft_strlen(char *str);

int		ft_strchr(const char *s, int c);

int		ft_count(long long num);

void	ft_define_flag(char **arr, va_list args, t_flags *flag);

int		ft_not_minus_p(t_flags *flag, long long num, int precision, int width);

int		ft_minus_p(t_flags *flag, long long num, int precision, int width);

int		ft_not_minus_n(t_flags *flag, long long num, int precision, int width);

int		ft_minus_n(t_flags *flag, long long num, int precision, int width);

int		ft_pos(t_flags *flag, long long num, int precision, int width);

int		ft_neg(t_flags *flag, long long num, int precision, int width);

void	ft_i_precision(unsigned long addr, t_flags *flag,
			int *precision, int *width);

void	ft_i_prec(long long num, t_flags *flag, int *precision, int *width);

int		ft_i_flag(t_flags *flag, long long num);

int		ft_min(unsigned long addr, t_flags *flag, int precision, int width);

int		ft_print_ptr(t_flags *flag, unsigned long *addr,
			int width, int precision);

void	ft_precision(char *str, t_flags *flag, int *precision, int *width);

int		ft_print_str(t_flags *flag, char *str, int precision, int width);

int		ft_print(t_flags *flag, char c, int width);

int		ft_printf_c(va_list args, t_flags *flag, char **arr);

int		ft_printf_s(va_list args, t_flags *flag);

int		ft_printf_p(va_list args, t_flags *flag);

int		ft_printf_dig(va_list args, t_flags *flag);

int		ft_not_minus_ui(unsigned int num, t_flags *flag,
			int precision, int width);

int		ft_minus_ui(unsigned int num, t_flags *flag,
			int precision, int width);

void	ft_i_ui(unsigned int num, t_flags *flag, int *precision, int *width);

int		ft_printf_ui(va_list args, t_flags *flag);

int		ft_not_minus_hex(unsigned int num, t_flags *flag,
			int precision, int width);

int		ft_minus_hex(unsigned int num, t_flags *flag, int precision, int width);

void	ft_i_hex(unsigned int num, t_flags *flag, int *precision, int *width);

int		ft_printf_hex(va_list args, t_flags *flag, char **arr);

int		ft_print_smth(char **arr, va_list args, t_flags *flag);

int		ft_read_flags(va_list args, char **arr);

int		ft_printf(const char *format, ...);

#endif