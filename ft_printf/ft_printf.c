/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 21:20:48 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/05/06 21:58:01 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(cont char *str, ...)
{
	va_list args;
	int		count;
	int		i;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			count += ft_handle_conversion(str[i], &args);
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

static	int	ft_handle_conversion(char c, va_list *args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*args, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(*args, char*)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(*args, void*)));
	else if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_print_uint(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), 0));
	else if (c == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), 1));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}
