/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 22:11:24 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/05/06 22:26:09 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	long	nb;
	char	c;
	int		count;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		count++;
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_print_int(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}
