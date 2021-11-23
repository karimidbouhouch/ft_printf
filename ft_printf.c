/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:23:32 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/11/23 21:02:37 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_find(const char c)
{
	int		i;
	char	*v;

	i = 0;
	v = "cspdiuxX%%";
	
	while (v[i])
	{
		if (c == v[i])
			return (v[i]);
		i++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	format;

	i = 0;
	count = 0;
	va_start(format, str);
	while (str[i])
	{
		if (str[i] != '%')
			count += ft_putchar(str[i]);
		else if (str[i] == '%')
		{
			i++;
			if (ft_find(str[i]) == 's')
				ft_putstr(va_arg(format, char *), &count);
			else if (ft_find(str[i]) == 'c')
				count += ft_putchar(va_arg(format, int));
			else if (ft_find(str[i]) == 'd' || ft_find(str[i]) == 'i')
				ft_putnbr(va_arg(format, int), &count);
			else if (ft_find(str[i]) == 'X')
				ft_puthex_upper(va_arg(format, unsigned int), &count);
			else if (ft_find(str[i]) == 'x')
				ft_puthex_lower(va_arg(format, unsigned int), &count);
			else if (ft_find(str[i]) == 'u')
				ft_putdec(va_arg(format, unsigned int), &count);
			else if (ft_find(str[i]) == 'p')
				ft_putadr(va_arg(format, unsigned long), &count);
			else if (ft_find(str[i]) == '%')
			{
				count += 1;
				write(1, "%%", 1);
			}
		}
		i++;
	}
	va_end(format);
	return (count);
}
