/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:56:31 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 09:56:36 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dst);
}

/*
#include <stdio.h>

int main(void)
{
    // 1. Estado inicial: Array de 10 bytes (9 números + \0).
    char str[] = "123456789";
    
    // 2. Ejecución: Movemos los primeros 5 bytes ("12345").
    // Origen: str (empieza en el '1').
    // Destino: str + 2 (empieza en el '3').
    // Al solaparse, tu memmove leerá desde atrás hacia adelante.
    ft_memmove(str + 2, str, 5);
    
    // 3. Verificación: Imprimimos el estado final de la memoria.
    printf("Resultado esperado: 121234589\n");
    printf("Tu resultado:       %s\n", str);
    
    return (0);
}
*/