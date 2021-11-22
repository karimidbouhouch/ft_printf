/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:06:46 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/11/22 21:38:41 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_upper(unsigned int nb,int *count)
{
	char *hex;
	char c;

	hex = "0123456789ABCDEF";
	if (nb < 16)
	{
		c = hex[nb];
		putchar(c);
		count +=1;
	}
	if (nb > 16)
	{
		ft_puthex_upper(nb / 16, count);
		ft_puthex_upper(nb % 16, count);
	}
}