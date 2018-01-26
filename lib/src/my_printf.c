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

	while (i < 11) {
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
	flag_t	struct_tab[] = {{'c', &prtf_putchar}, {'%', &prtf_percent},
		{'s', &prtf_putstr}, {'d', &prtf_put_nbr_list},
		{'i', &prtf_put_nbr_list}, {'x', &prtf_put_hexa_low},
		{'X', &prtf_put_hexa_up}, {'o', &prtf_put_octal},
		{'b', &prtf_put_bin}, {'p', &prtf_put_pointer},
		{'u', &prtf_unsigned}};

	va_start(ap, str);
	while (str[i]) {
		if (str[i] == '%') {
			flag = found_flag(str[i + 1], struct_tab);
			if (flag == 84)
				return (84);
			if (struct_tab[flag].fptr(ap) == 84)
				return (84);
			i++;
		} else
			write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (0);
}
