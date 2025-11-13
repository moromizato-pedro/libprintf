/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:54:55 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/11/13 02:05:06 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_parse_specifier(char c, va_list ap, int *count)
{
	if (c == 'c')
		return (ft_putchar_pf(va_arg(ap, int), count));
	else if (c == 's')
		return (ft_putstr_pf(va_arg(ap, char *), count));
	else if (c == 'p')
		return (ft_putptr_pf(va_arg(ap, long), count));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_pf(va_arg(ap, int), count));
	else if (c == 'u')
		return (ft_putuint_pf(va_arg(ap, unsigned int), count));
	else if (c == 'x')
		return (ft_puthex_pf(va_arg(ap, unsigned int), 'l', count));
	else if (c == 'X')
		return (ft_puthex_pf(va_arg(ap, unsigned int), 'u', count));
	else if (c == '%')
		return (ft_putchar_pf('%', count));
	return (va_end(ap), -1);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_parse_specifier(*format, ap, &count) == -1)
				return (-1);
		}
		else
			ft_putchar_pf(*format, &count);
		format++;
	}
	va_end(ap);
	return (count);
}
/*
int	main(void)
{
	int		i;
	int		j;
	//int		a;
	//char	*s;

	//s = 0;
	//a = 0;
	//i = ft_printf(	" %x \n", LONG_MIN);
	//j = printf(	" %x \n", (unsigned int)LONG_MIN);
	//printf(" %ld %ld\n", LONG_MIN, LONG_MAX);
	i = ft_printf(" %p %p\n", LONG_MIN, LONG_MAX);
	j = printf(" %p %p\n", (void *)LONG_MIN, (void *)LONG_MAX);
	printf("i: %d | j: %d\n", i, j);
}*/
