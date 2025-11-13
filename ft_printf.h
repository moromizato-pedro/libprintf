/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:42:24 by pedrohe3          #+#    #+#             */
/*   Updated: 2025/11/13 01:55:19 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_putchar_pf(char c, int *count);
int	ft_putstr_pf(char *s, int *count);
int	ft_putptr_pf(long ptr, int *count);
int	ft_putnbr_base_pf(long nbr, char *base, int *count);
int	ft_puthex_pf(unsigned int nbr, char hcase, int *count);
int	ft_putnbr_pf(int nbr, int *count);
int	ft_putuint_pf(unsigned int nbr, int *count);

#endif
