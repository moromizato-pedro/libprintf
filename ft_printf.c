/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:54:55 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/11/10 18:58:20 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include "libft.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list ap;
	const char	*s;
	int	*count;
	int	ret;

	va_start(ap, format);
	s = format;
	count = 0;
	ret = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'c')
				ret = ft_putchar_pf(va_arg(ap, int), count);
			if (*s == 's')
				ret = ft_putstr_pf(va_arg(ap, char *), count);
			if (ret == -1)
			{
				va_end(ap);
				return (-1);
			}
		}
		s++;
	}
	va_end(ap);
	return (*count);
}

int	main(void)
{
	int	i;
	
	i = ft_printf("Hello W%crld\n", 'o');
	i = ft_printf("Hello %s\n", "World");
	printf("i: %d\nEND\n", i);
	return (0);
}
