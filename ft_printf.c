/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:23:32 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/11/24 12:47:18 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_percent(void)
{
	write(1, "%%", 1);
	return (1);
}

static void	ft_printf_2(char c, int *count, void *args)
{
	if (c == 's')
		ft_putstr((char *)args, count);
	else if (c == 'd' || c == 'i')
		ft_putnbr((int)args, count);
	else if (c == 'X')
		ft_puthex_upper((unsigned int)args, count);
	else if (c == 'x')
		ft_puthex_lower((unsigned int)args, count);
	else if (c == 'u')
		ft_putdec((unsigned int)args, count);
	else if (c == 'p')
		ft_putadr((unsigned long)args, count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	arg_list;

	i = 0;
	count = 0;
	va_start(arg_list, s);
	while (s[i])
	{
		if (s[i] != '%')
			count += ft_putchar(s[i]);
		else if (s[i] == '%')
		{
			i++;
			if (s[i] == 'c')
				count += ft_putchar(va_arg(arg_list, int));
			else if (s[i] == '%')
				count += ft_percent();
			else
				ft_printf_2(s[i], &count, va_arg(arg_list, void *));
		}
		i++;
	}
	va_end(arg_list);
	return (count);
}
