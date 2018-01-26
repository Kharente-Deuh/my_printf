/*
** EPITECH PROJECT, 2017
** conv_base.c
** File description:
** convert a number in a base
*/

#include "printf.h"

void	conv_base_norm(char **str, char *base_content, long unsigned int *nb, int base)
{
	int	tmp = *nb % base;

	(*str)[0] = base_content[tmp];
	(*str)[1] = '\0';
	*nb /= base;
}

char	*prtf_conv_base(char *base_content, int base, long unsigned int nb)
{
	char	*str = malloc(sizeof(char) * 2);
	char	*base_tmp = NULL;

	if (str == NULL)
		return (NULL);
	conv_base_norm(&str, base_content, &nb, base);
	while (nb > 0) {
		if ((base_tmp = malloc(sizeof(char) * 2)) == NULL)
			return (NULL);
		conv_base_norm(&base_tmp, base_content, &nb, base);
		if ((str = prtf_strcat(str, base_tmp)) == NULL)
			return (NULL);
	}
	str = prtf_revstr(str);
	return (str);
}
