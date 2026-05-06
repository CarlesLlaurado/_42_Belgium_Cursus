/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 22:27:15 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/05/06 22:30:09 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(unsigned int n)
{
	long	nb;
	int		count;
	char	c;

	count = 0;
	nb = n;
	if (nb >= 10)
		count += ft_print_uint(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}
