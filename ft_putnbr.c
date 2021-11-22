/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:10:33 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/11/22 19:59:11 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr(int nb, int *count)
{
	char c;

	if (nb < 0)
	{
		nb = nb * (-1);
		ft_putchar('-');
		*count+=1;
	}
	if (nb > 0 && nb < 10)
	{
		c = nb + '0';
		ft_putchar(c);
		*count+=1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, count);
		ft_putnbr(nb % 10, count);
	}
}