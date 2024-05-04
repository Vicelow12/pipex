/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:45:40 by ngaulthi          #+#    #+#             */
/*   Updated: 2023/12/18 15:06:06 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	write_char(int chr, ssize_t *wcount)
{
	if (write(1, &chr, 1) == -1)
		*wcount = -1;
	else
		(*wcount)++;
}

void	write_str(char *str, ssize_t *wcount)
{
	size_t	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		if (write(1, &str[i++], 1) == -1)
		{
			*wcount = -1;
			break ;
		}
		else
			(*wcount)++;
	}
}

void	write_nbr(int nb, ssize_t *wcount)
{
	char	digit;

	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			nb = 147483648;
			write_str("-2", wcount);
		}
		else
		{
			write_char('-', wcount);
			nb = -nb;
		}
	}
	if (nb >= 10)
		write_nbr(nb / 10, wcount);
	digit = '0' + nb % 10;
	write_char(digit, wcount);
}

void	recursive_ptr(unsigned long long ptr, ssize_t *wcount)
{
	char	*base;

	base = "0123456789abcdef";
	if (ptr >= 16)
		recursive_ptr(ptr / 16, wcount);
	write_char(base[ptr % 16], wcount);
}

void	write_ptr(unsigned long long ptr, ssize_t *wcount)
{
	if (!ptr)
		write_str("(nil)", wcount);
	else
	{
		write_str("0x", wcount);
		recursive_ptr(ptr, wcount);
	}
}
