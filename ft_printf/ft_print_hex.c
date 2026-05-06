/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 22:31:08 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/05/06 22:36:26 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, int uppercase)
{
	long	nb;
	int		count;
	char	c;
	char	*digits;

	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	count = 0;
	nb = n;
	if (nb >= 16)
		count += ft_print_hex(nb / 16, uppercase);
	c = digits[nb % 16];
	write(1, &c, 1);
	count++;
	return (count);
}
