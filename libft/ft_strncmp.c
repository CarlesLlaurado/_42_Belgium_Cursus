/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:01:21 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 10:01:23 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

// ---------------------------------------------------------
// TEST PRINCIPAL
// ---------------------------------------------------------
int main(void)
{
    printf("--- TEST ft_strncmp ---\n");

    // Test 1: Cadenas idénticas (Debe devolver 0)
    printf("Test 1 (Iguales)   -> %d\n", ft_strncmp("Admin", "Admin", 5));

    // Test 2: s1 es mayor ('z' > 'a' en ASCII. Devuelve positivo)
    printf("Test 2 (s1 mayor)  -> %d\n", ft_strncmp("Admiz", "Admia", 5));

    // Test 3: s2 es mayor (Devuelve negativo)
    printf("Test 3 (s2 mayor)  -> %d\n", ft_strncmp("Admia", "Admiz", 5));

    // Test 4: El freno 'n'
    // Falla en la 5ta letra, pero comparamos 4. (Devuelve 0)
    printf("Test 4 (Límite OK) -> %d\n", ft_strncmp("Admiz", "Admia", 4));

    // Test 5: String vacío vs String con datos
    printf("Test 5 (s1 vacío)  -> %d\n", ft_strncmp("", "Admin", 5));

    return (0);
}

// =========================================================
// CTO Note: El Inspector de Aduanas (ELI5).
// =========================================================
// Compara dos palabras letra a letra, con un límite estricto:
// solo revisa hasta un máximo de 'n' caracteres.
// 
// Si son idénticas hasta ese tope, devuelve 0 (Aprobado).
// Si hay una letra distinta, las resta y devuelve ese número.
// Negativo = primera palabra va antes en el diccionario.
// Positivo = va después.
// 
// Negocio: Validar comandos ("START") sin importar la basura
// de texto que el usuario haya añadido al final por error.
*/