/*
** EPITECH PROJECT, 2017
** put_base.c
** File description:
** convert a number in a base a print it
*/

#include "printf.h"

int	my_put_base(char *base_content, int base, unsigned int nb)
{
	int	tmp = 0;
	char	*str = malloc(sizeof(char) * 2);
	char	*base_tmp = NULL;

	if (str == NULL)
		return (84);
	tmp = nb % base;
	str[0] = base_content[tmp];
	str[1] = '\0';
	nb /= base;
	while (nb > 0)
	{
		tmp = nb % base;
		base_tmp = malloc(sizeof(char) * 2);
		if (base_tmp == NULL)
			return (84);
		base_tmp[0] = base_content[tmp];
		base_tmp[1] = '\0';
		str = prtf_strcat(str, base_tmp);
		nb /= base;
	}
	str = prtf_revstr(str);
	write(1, str, prtf_strlen(str));
	free(str);
	return (0);
}

void	my_put_hexa_low(va_list ap)
{
	char		base[16] = "0123456789abcdef";
	unsigned int	nb = va_arg(ap, unsigned int);

	if (my_put_base(base, 16, nb) == 84)
		return;
}

void	my_put_hexa_up(va_list ap)
{
	char		base[16] = "0123456789ABCDEF";
	unsigned int	nb = va_arg(ap, unsigned int);

	if (my_put_base(base, 16, nb) == 84)
		return;
}

void	my_put_octal(va_list ap)
{
	char		base[] = "0123456789";
	unsigned int	nb = va_arg(ap, unsigned int);

	if (my_put_base(base, 8, nb) == 84)
		return;
}
