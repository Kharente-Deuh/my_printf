/*
** EPITECH PROJECT, 2017
** big_s.c
** File description:
** put octal number of a character
*/

#include "printf.h"

int	is_printable(char c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}

void	print_octal(char c)
{
	char 	*str = malloc(sizeof(char) * 512);
	int	i = 0;

	if (str == NULL)
		return;
	while (c > 0)
	{
		str[i] = (c % 8) + '0';
		c /= 8;
		i++;
	}
	while (3 - i > 0) {
		str[i] = '0';
		i++;
	}
	str[i] = '\\';
	str[i + 1] = '\0';
	str = prtf_revstr(str);
	write(1, str, prtf_strlen(str));
	free(str);
}

void	verif(char *str)
{
	int	i = 0;
	int	print;

	while (str[i]) {
		print = is_printable(str[i]);
		if (print == 1)
			write(1, &str[i], 1);
		else
			print_octal(str[i]);
		i++;
	}
}

void	my_big_s(va_list ap)
{
	char	*str = va_arg(ap, char *);

	if (str[0] == '\0')
		write(1, "(null)", 6);
	else
		verif(str);
}
