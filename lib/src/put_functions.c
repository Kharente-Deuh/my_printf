/*
** EPITECH PROJECT, 2017
** put_functions.c
** File description:
** all the put functions used
*/

#include <limits.h>
#include "printf.h"

void	prtf_putchar(va_list ap)
{
	char	c = va_arg(ap, int);

	write(1, &c, 1);
}

void	prtf_putstr(va_list ap)
{
	char	*str = va_arg(ap, char *);
	int	len = prtf_strlen(str);

	if (str == NULL)
		exit (84);
	if (len == 0)
		write(1, "(null)", 6);
	else
		write(1, str, len);
}

void	prtf_percent(va_list UNUSED ap)
{
	write(1, "%", 1);
}

void	prtf_put_nbr(int nb)
{
	char	c = 0;

	if (nb == INT_MIN)
		write(1, "-2147483648", 11);
	else {
		if (nb < 0) {
			nb = -nb;
			write(1, "-", 1);
		} else if (nb >= 10) {
			prtf_put_nbr(nb / 10);
			prtf_put_nbr(nb % 10);
		} else {
			c = nb + '0';
			write(1, &c, 1);
		}
	}
}

void	prtf_put_nbr_list(va_list ap)
{
	prtf_put_nbr(va_arg(ap, int));
}
