/*
** EPITECH PROJECT, 2017
** printf.h
** File description:
** printf
*/

#ifndef __PRINTF_H__
# define __PRINTF_H__

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

# ifndef __UNUSED__
#  define UNUSED	__attribute__((unused))
# endif /* UNUSED */

typedef struct flag_struct {
	char	flag;
	void	(*fptr)(va_list);
} flag_t;

int 	my_printf(char *, ...);
void	prtf_putchar(va_list);
void	prtf_putstr(va_list);
void	prtf_put_nbr(int);
void	prtf_put_nbr_list(va_list);
void	prtf_percent(va_list);
void	my_big_s(va_list);
char	*prtf_revstr(char *);
void	my_put_hexa_low(va_list);
void	my_put_hexa_up(va_list);
void	my_put_octal(va_list);
char	*prtf_strcat(char *, char *);
int	prtf_strlen(char *);

#endif /* __PRINTF_H__ */
