#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    printf("22) printf :  %*.5s %*.5s.\n", -10, "123", 10, "4567");
	ft_printf("ft_printf :  %*.5s %*.5s.\n", -10, "123", 10, "4567");

    printf("23) printf :  %*.5s %*.5s.\n", 10, "123", -10, "4567");
	ft_printf("ft_printf :  %*.5s %*.5s.\n", 10, "123", -10, "4567");

    printf("24) printf :  %*.5s %*.5s.\n", -10, "123", -10, "4567");
	ft_printf("ft_printf :  %*.5s %*.5s.\n", -10, "123", -10, "4567");

    printf("36) printf :  %.*s.\n", -2, NULL);
	ft_printf("ft_printf :  %.*s.\n", -2, NULL);
}
