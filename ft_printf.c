/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:23:32 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/11/23 22:37:19 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_percent(void)
{
	write(1, "%%", 1);
	return (1);
}

static void	ft_printf_2(char str, int *count, void *args)
{
	if (str == 's')
		ft_putstr((char *)args, count);
	else if (str == 'd' || str == 'i')
		ft_putnbr((int)args, count);
	else if (str == 'X')
		ft_puthex_upper((unsigned int)args, count);
	else if (str == 'x')
		ft_puthex_lower((unsigned int)args, count);
	else if (str == 'u')
		ft_putdec((unsigned int)args, count);
	else if (str == 'p')
		ft_putadr((unsigned long)args, count);
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
			if (str[i] == 'c')
				count += ft_putchar(va_arg(format, int));
			else if (str[i] == '%')
				count += ft_percent();
			else
				ft_printf_2(str[i], &count, va_arg(format, void *));
		}
		i++;
	}
	va_end(format);
	return (count);
}
