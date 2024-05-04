/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:40:24 by ngaulthi          #+#    #+#             */
/*   Updated: 2023/11/28 14:46:47 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	nb_digit(int count, int nb)
{
	if (nb == -2147483648)
	{
		return (11);
	}
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static	int	lowest_nb(char *number)
{
	number[0] = '-';
	number[1] = '2';
	return (147483648);
}

char	*ft_itoa(int nb)
{
	char	*number;
	int		str_len;

	str_len = nb_digit(1, nb);
	number = malloc(sizeof(char) * (str_len + 1));
	if (!number)
		return (NULL);
	number[str_len] = '\0';
	if (nb == -2147483648)
		nb = lowest_nb(number);
	if (nb < 0)
	{
		nb = -nb;
		number[0] = '-';
	}
	while (nb >= 10)
	{
		str_len--;
		number[str_len] = '0' + nb % 10;
		nb = nb / 10;
	}
	number[str_len - 1] = '0' + nb;
	return (number);
}
