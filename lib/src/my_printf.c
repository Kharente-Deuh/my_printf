/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** printf
*/

#include "printf.h"

int	found_flag(char c, flag_t *struct_tab)
{
	int	i = 0;

	while (i < 9) {
		if (c == struct_tab[i].flag)
			return (i);
		i++;
	}
	return (84);
}

int	my_printf(char *str, ...)
{
	va_list	ap;
	int	i = 0;
	int	flag;
	flag_t	struct_tab[] = {{'c', &prtf_putchar},
		{'%', &prtf_percent}, {'s', &prtf_putstr},
		{'S', &my_big_s}, {'d', &prtf_put_nbr_list},
		{'i', &prtf_put_nbr_list}, {'x', &my_put_hexa_low},
		{'X', &my_put_hexa_up}, {'o', &my_put_octal}};

	va_start(ap, str);
	while (str[i]) {
		if (str[i] == '%') {
			flag = found_flag(str[i + 1], struct_tab);
			if (flag == 84)
				return (84);
			struct_tab[flag].fptr(ap);
			i++;
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (0);
}
