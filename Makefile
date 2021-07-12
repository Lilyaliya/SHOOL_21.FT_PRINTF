NAME = libftprintf.a

SRC =	ft_additional_plus.c		ft_additional.c			ft_char.c\
		ft_check_minus_dig.c		ft_digit.c				ft_hex.c\
		ft_pointer.c				ft_printf.c				ft_string.c\
		ft_ui.c\

OBJS	= $(SRC:.c=.o)

BONUS	=	$(SRC)

BONUS_OBJS	= $(BONUS:.c=.o)

%.o: %.c	ft_printf.h
		${CC} $(CFLAGS) $< -o $@

CFLAGS = -Wall -Wextra -Werror -c

$(NAME) : $(OBJS)
		ar rcs $(NAME) $?

RM	= rm -f

CC	= gcc

all : $(NAME)

clean :
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all bonus

bonus:		$(BONUS_OBJS)
			ar rcs $(NAME) $?

.PHONY : clean fclean all re bonus