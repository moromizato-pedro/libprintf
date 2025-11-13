/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:43:35 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/11/12 23:08:43 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(char *s, int *count)
{
	if (!count)
		return (-1);
	else if (!s)
		return (ft_putstr_pf("(null)", count));
	while (*s)
	{
		if (ft_putchar_pf(*s, count) == -1)
			return (-1);
		s++;
	}
	return (1);
}
