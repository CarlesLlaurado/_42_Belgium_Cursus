/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 09:54:10 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/05/07 10:14:16 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex_ptr(unsigned long n);

int	ft_print_ptr(void *ptr)
{
	unsigned long	nb;
	int				count;

	if (!ptr)
		return (ft_print_str("(nil)"));
	count = 2;
	nb = (unsigned long) ptr;
	write(1, "0x", 2);
	count += ft_print_hex_ptr(nb);
	return (count);
}

static int	ft_print_hex_ptr(unsigned long n)
{
	unsigned long	nb;
	int				count;
	char			c;
	char			*digits;

	digits = "0123456789abcdef";
	count = 0;
	nb = n;
	if (nb >= 16)
		count += ft_print_hex_ptr(nb / 16);
	c = digits[n % 16];
	write(1, &c, 1);
	count++;
	return (count);
}
