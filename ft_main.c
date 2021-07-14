#include "ft_printf.h"
#include <stdio.h>

static char	a01;
static unsigned char a02;
static short a03;
static unsigned short a04;
static int a05;
static unsigned int a06;
static long a07;
static unsigned long a08;
static long long a09;
static unsigned long long a10;
static char *a11;
static void *a12;

int main(void)
{
    printf("186) printf :   .%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p.\n",&a01,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10);
	ft_printf("ft_printf :   .%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p.\n",&a03,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10);

    printf("188) printf :  .%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p.\n",&a01,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10);
	ft_printf("ft_printf :  .%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p.\n",&a01,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10);

    printf("188) printf :  .%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p.\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("ft_printf :  .%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p.\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);

    getchar();
}
