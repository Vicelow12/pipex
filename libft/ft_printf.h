/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:38:07 by ngaulthi          #+#    #+#             */
/*   Updated: 2023/12/18 14:55:30 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *text, ...);
void	write_char(int chr, ssize_t *wcount);
void	write_str(char *str, ssize_t *wcount);
void	write_nbr(int nb, ssize_t *wcount);
void	recursive_ptr(unsigned long long ptr, ssize_t *wcount);
void	write_ptr(unsigned long long ptr, ssize_t *wcount);

#endif
