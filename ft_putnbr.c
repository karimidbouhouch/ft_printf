/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:10:33 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/11/23 18:44:23 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long long nb, int *count)
{
	char	c;

	if (nb < 0)
	{
		nb = nb * (-1);
		write(1, "-", 1);
		*count += 1;
	}
	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
		*count += 1;
	}
	else
	{
		ft_putnbr(nb / 10, count);
		ft_putnbr(nb % 10, count);
	}
}
