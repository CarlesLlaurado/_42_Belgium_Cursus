/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:03:24 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 10:03:27 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*
#include <stdio.h>

int main(void)
{
    printf("--- TEST ft_toupper ---\n");
    printf("Minúscula (a) -> %c\n", ft_toupper('a'));
    printf("Minúscula (z) -> %c\n", ft_toupper('z'));
    printf("Mayúscula (M) -> %c\n", ft_toupper('M'));
    printf("Símbolo   (5) -> %c\n", ft_toupper('5'));
    
    return (0);
}
*/