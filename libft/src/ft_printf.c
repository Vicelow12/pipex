/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:37:48 by ngaulthi          #+#    #+#             */
/*   Updated: 2023/12/21 15:39:51 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	write_char(int chr, ssize_t *wcount);
void	write_str(char *str, ssize_t *wcount);
void	write_nbr(int nb, ssize_t *wcount);
void	recursive_ptr(unsigned long long ptr, ssize_t *wcount);
void	write_ptr(unsigned long long ptr, ssize_t *wcount);

static void	rb(unsigned int nb, char *base, unsigned int b_lgt, ssize_t *wcount)
{
	if (nb >= b_lgt)
		rb(nb / b_lgt, base, b_lgt, wcount);
	if (*wcount != -1)
		write_char(base[nb % b_lgt], wcount);
}

static void	write_nbbase(unsigned int nb, char *base, ssize_t *wcount)
{
	unsigned int	b_lgt;
	size_t			i;

	b_lgt = 0;
	i = 0;
	while (base[i])
	{
		b_lgt++;
		i++;
	}
	rb(nb, base, b_lgt, wcount);
}

static void	write_arg(char format, va_list argptr, ssize_t *wcount)
{
	if (format == '\0')
		*wcount = -1;
	else if (format == 'c')
		write_char(va_arg(argptr, int), wcount);
	else if (format == 's')
		write_str(va_arg(argptr, char *), wcount);
	else if (format == 'p')
		write_ptr(va_arg(argptr, unsigned long long), wcount);
	else if (format == 'd' || format == 'i')
		write_nbr(va_arg(argptr, int), wcount);
	else if (format == 'u')
		write_nbbase(va_arg(argptr, unsigned int), "0123456789", wcount);
	else if (format == 'x')
		write_nbbase(va_arg(argptr, unsigned int), "0123456789abcdef", wcount);
	else if (format == 'X')
		write_nbbase(va_arg(argptr, unsigned int), "0123456789ABCDEF", wcount);
	else if (format == '%')
		write_char('%', wcount);
	else
	{
		write_char('%', wcount);
		write_char(format, wcount);
	}
}

int	ft_printf(const char *text, ...)
{
	ssize_t	i;
	ssize_t	wcount;
	va_list	argptr;

	if (!text)
		return (-1);
	va_start(argptr, text);
	i = 0;
	wcount = 0;
	while (text[i])
	{
		if (wcount == -1)
			break ;
		if (text[i] == '%')
		{
			i++;
			write_arg(text[i++], argptr, &wcount);
		}
		else
			write_char(text[i++], &wcount);
	}
	va_end(argptr);
	return (wcount);
}
