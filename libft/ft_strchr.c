/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:59:03 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 09:59:06 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

// =========================================================
// CTO Note: El buscador con puntero láser (ELI5).
// =========================================================
// Imagina que lees una frase letra por letra buscando la 'C'.
// Cuando la encuentras, pones tu dedo encima de esa 'C'.
// 
// La función devuelve esa posición exacta (el puntero). Así puedes 
// imprimir todo lo que hay desde tu dedo hasta el final.
// Si la letra no existe, devuelves NADA (NULL).

/*
#include <stdio.h>

int main(void)
{
    // Nuestra frase de prueba para la evaluación
    char str[] = "Programar en C da dolor de cabeza";
    char *resultado;

    printf("--- TEST ft_strchr ---\n");
    
    // Test 1: Búsqueda exitosa. 
    // Ponemos el dedo en la 'C'. Imprimirá: "C da dolor de cabeza"
    resultado = ft_strchr(str, 'C');
    printf("Buscar 'C' -> %s\n", resultado ? resultado : "NULL");

    // Test 2: Búsqueda fallida.
    // La 'Z' no está en la frase. Devuelve NULL de forma segura.
    resultado = ft_strchr(str, 'Z');
    printf("Buscar 'Z' -> %s\n", resultado ? resultado : "NULL");

    // Test 3: El terminador nulo (Crash test).
    // Verificamos si encuentra el final invisible de la palabra.
    resultado = ft_strchr(str, '\0');
    if (resultado && *resultado == '\0')
        printf("Buscar '\\0' -> Encontrado al final del string\n");
    else
        printf("Buscar '\\0' -> Falla el puntero\n");

    return (0);
}
*/