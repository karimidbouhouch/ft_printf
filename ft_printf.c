/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:23:32 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/11/22 22:09:18 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char ft_find(const char c)
{
	int i;
	char *v;

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

int ft_printf(const char *str, ...)
{
	int i;
	int count;

	i = 0;
	count = 0;
	va_list valist;
	va_start(valist, str);
	while (str[i])
	{
		if (str[i] != '%')
			count += ft_putchar(str[i]);
		else if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				count += ft_putstr(va_arg(valist, char *));
			else if (str[i] == 'c')
				count += ft_putchar(va_arg(valist, int));
			else if (str[i] == 'd' || str[i] == 'i')
				ft_putnbr(va_arg(valist, int), &count);
			else if (str[i] == 'X')
				ft_puthex_upper(va_arg(valist, int), &count);
			else if (str[i] == 'x')
				ft_puthex_lower(va_arg(valist, int), &count);
			else if (str[i] == '%')
				ft_putstr("%%");
		}
		i++;
	}
	va_end(valist);
	return (count);
}

int main()
{
	// char *s = "karim";
	// char c = 'K';
	// int i = ft_printf("%c-hello %s",c,s);
	printf("%x\n", 123);
	ft_printf("%x", 123);
	//printf("%d",(-1337));
}