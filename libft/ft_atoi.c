/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:28:19 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 10:37:20 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*

#include <stdio.h>
int	main(void)
{
	char str[] = "    	\t\n-20000000000";
	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
	char str2[] = "    	+555";
	printf("%d\n", ft_atoi(str2));
	printf("%d\n", atoi(str2));
	char str3[] = "7-123";
	printf("%d\n", ft_atoi(str3));
	printf("%d\n", atoi(str3));
	char str4[] = "\t\n-0";
	printf("%d\n", ft_atoi(str4));
	printf("%d\n", atoi(str4));


	return (0);
}
*/
