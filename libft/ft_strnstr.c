/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:01:35 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 10:01:42 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && (i + j) < len && big[i + j] == little[j])
			j++;
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

// ---------------------------------------------------------
// TEST PRINCIPAL
// ---------------------------------------------------------
int main(void)
{
    char *big = "No hay que buscar pajaros en el nido de antaño";
    char *little = "pajaros";
    char *res;

    printf("--- TEST ft_strnstr ---\n");

    // Test 1: Encuentra la aguja dentro del límite
    res = ft_strnstr(big, little, 20);
    printf("Test 1 (Encontrado) -> %s\n", res ? res : "NULL");

    // Test 2: La aguja existe, pero el límite 'len' es corto
    res = ft_strnstr(big, little, 10);
    printf("Test 2 (Limite len) -> %s\n", res ? res : "NULL OK");

    // Test 3: Aguja vacía (debe devolver el string original)
    res = ft_strnstr(big, "", 10);
    printf("Test 3 (Vacia)-> %s\n", (res == big) ? "Original OK" : "Error");

    // Test 4: No existe
    res = ft_strnstr(big, "unicornio", 40);
    printf("Test 4 (No existe)  -> %s\n", res ? "Error" : "NULL OK");

    return (0);
}

// =========================================================
// CTO Note: La Aguja en el Pajar con Límite (ELI5).
// =========================================================
// Esta función busca una palabra pequeña ("little") dentro de 
// una frase grande ("big"), pero con un cronómetro ("len").
// 
// Si dejas de buscar porque se acaba el tiempo ('len') antes 
// de terminar de encontrar la palabra, devuelves NULL. 
// 
// Si la encuentras a tiempo, pones el dedo (puntero) justo 
// donde empieza la palabra pequeña dentro de la grande.
// 
// Negocio: Se usa para buscar virus o patrones en datos que 
// vienen de internet, asegurándote de no leer memoria de más 
// para que nadie pueda hackearte por desbordamiento.
*/