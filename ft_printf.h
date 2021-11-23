/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:26:30 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/11/23 18:41:48 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(long long nb, int *count);
void	ft_puthex_upper(unsigned int nb, int *count);
void	ft_puthex_lower(unsigned int nb, int *count);
void	ft_putdec(unsigned int nb, int *count);
void	ft_putadr(unsigned long p, int *count);
#endif