/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:08:54 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/11/23 18:47:03 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putdec(unsigned int nb, int *count)
{
	char	c;

	if (nb < 10)
	{
		c = nb + '0';
		ft_putchar(c);
		*count += 1;
	}
	if (nb > 9)
	{
		ft_putdec(nb / 10, count);
		ft_putdec(nb % 10, count);
	}
}
