/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:03:08 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 10:03:13 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*
#include <stdio.h>

int main(void)
{
    printf("--- TEST ft_tolower ---\n");
    printf("Mayúscula (A) -> %c\n", ft_tolower('A'));
    printf("Mayúscula (Z) -> %c\n", ft_tolower('Z'));
    printf("Minúscula (m) -> %c\n", ft_tolower('m'));
    printf("Símbolo   (5) -> %c\n", ft_tolower('5'));
    
    return (0);
}
*/