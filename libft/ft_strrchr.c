/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:01:55 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 10:02:00 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

// =========================================================
// CTO Note: El buscador que lee al revés (ELI5).
// =========================================================
// Hace exactamente lo mismo que strchr, pero empieza a buscar
// desde el final de la frase hacia el principio.
// 
// ¿Para qué sirve? Imagina que tienes el archivo "foto.gato.png".
// Si usas el buscador normal (strchr), se parará en el primer 
// punto (".gato.png"). Pero si usas este buscador inverso, 
// encontrará el ÚLTIMO punto (".png").

/*
#include <stdio.h>

// ---------------------------------------------------------
// DEPENDENCIA: ft_strlen (Para calcular desde dónde empezar)
// ---------------------------------------------------------
size_t  ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

// ---------------------------------------------------------
// TEST PRINCIPAL
// ---------------------------------------------------------
int main(void)
{
    // Una frase con letras repetidas para comprobar la lógica
    char str[] = "mi.super.virus.mp4";
    char *resultado;

    printf("--- TEST ft_strrchr ---\n");
    
    // Test 1: Búsqueda del último punto.
    // Debería ignorar los primeros y capturar solo la extensión: ".mp4"
    resultado = ft_strrchr(str, '.');
    printf("Buscar último '.' -> %s\n", resultado ? resultado : "NULL");

    // Test 2: Búsqueda de una letra repetida.
    // Busca la 'm'. Como lee al revés, encuentra la de ".mp4", no la de "mi".
    resultado = ft_strrchr(str, 'm');
    printf("Buscar última 'm' -> %s\n", resultado ? resultado : "NULL");

    // Test 3: Búsqueda fallida.
    // La 'Z' no está. Devuelve NULL de forma segura.
    resultado = ft_strrchr(str, 'Z');
    printf("Buscar letra  'Z' -> %s\n", resultado ? resultado : "NULL");

    // Test 4: El terminador nulo (Crash test).
    // Verificamos si encuentra el final invisible de la palabra.
    resultado = ft_strrchr(str, '\0');
    if (resultado && *resultado == '\0')
        printf("Buscar '\\0'        -> Encontrado al final del string\n");
    else
        printf("Buscar '\\0'        -> Falla el puntero\n");

    return (0);
}
*/