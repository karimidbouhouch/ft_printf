/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:43:18 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/11/23 18:45:57 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex(unsigned long nb, int *count)
{
	char	*hex;
	char	c;

	hex = "0123456789abcdef";
	if (nb < 16)
	{
		c = hex[nb];
		write(1, &c, 1);
		*count += 1;
	}
	else
	{
		ft_puthex(nb / 16, count);
		ft_puthex(nb % 16, count);
	}
}

void	ft_putadr(unsigned long p, int *count)
{
	write(1, "0x", 2);
	*count += 2;
	ft_puthex(p, count);
}
