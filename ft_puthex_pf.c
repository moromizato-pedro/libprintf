/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:05:13 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/11/13 01:52:33 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_pf(unsigned int nbr, char hcase, int *count)
{
	if (!count)
		return (-1);
	if (hcase == 'l')
		return (ft_putnbr_base_pf(nbr, "0123456789abcdef", count));
	else if (hcase == 'u')
		return (ft_putnbr_base_pf(nbr, "0123456789ABCDEF", count));
	return (-1);
}
