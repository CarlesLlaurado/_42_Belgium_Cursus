/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:00:33 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 10:00:35 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

/*
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int main(void)
{
    // Escenario 1: Buffer grande (Todo cabe perfectamente)
    char buffer_amplio[20];
    size_t res1;
    
    res1 = ft_strlcpy(buffer_amplio, "SaaS Ixelles", 20);
    printf("Test 1 (Espacio OK): %s\n", buffer_amplio);
    printf("Bytes intentados:    %zu\n\n", res1);

    // Escenario 2: Buffer pequeño (Forzamos el truncamiento)
    // Solo caben 4 letras + 1 byte para el \0 de seguridad.
    char buffer_limitado[6]; 
    size_t res2;
    
    res2 = ft_strlcpy(buffer_limitado, "SaaS Lausana", 6);
    printf("Test 2 (Recortado):  %s\n", buffer_limitado);
    printf("Bytes intentados:    %zu\n", res2);

    return (0);
}
*/