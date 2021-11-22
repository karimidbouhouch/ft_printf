/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:42:17 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/11/22 21:49:46 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_lower(unsigned int nb, int *count)
{
	char *hex;
	char	c;

	hex = "0123456789abcdef";
	if (nb < 16)
	{
		c = hex[nb];
		ft_putchar(c);
		*count += 1;
	}
	if (nb > 16)
	{
		ft_puthex_lower(nb / 16, count);
		ft_puthex_lower(nb % 16, count);
	}
	
}