/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:55:34 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 09:55:37 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
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
    // Usamos un array con un 0 en medio para demostrar que
    // memchr NO se detiene como lo haría una función de string.
    unsigned char data[] = {10, 20, 0, 40, 50};
    void *res;

    printf("--- TEST ft_memchr ---\n");

    // Test 1: Buscar un valor existente
    res = ft_memchr(data, 40, 5) ;
    if (res)
        printf("Test 1 (Encontrado) -> Valor: %d\n", *(unsigned char *)res);

    // Test 2: Buscar algo que no existe en los primeros n bytes
    res = ft_memchr(data, 50, 3);
    printf("Test 2 (Limite n)   -> %s\n", res ? "Error" : "NULL OK");

    // Test 3: Buscar el valor 0 (donde strchr se detendría)
    res = ft_memchr(data, 0, 5);
    if (res)
        printf("Test 3 (Cero/Null)  -> Encontrado en posicion 2\n");

    return (0);
}

// =========================================================
// CTO Note: El Escáner de Rayos X (ELI5).
// =========================================================
// A diferencia de las funciones que buscan letras en frases, 
// esta no se fía de los puntos finales (\0). 
// 
// Escanea un bloque de memoria byte a byte hasta que encuentra 
// el valor que buscas o se acaba el límite 'n' que le diste.
// Si lo encuentra, te da la dirección exacta de memoria (puntero). 
// Si no, te devuelve NULL.
// 
// Negocio: Fundamental para leer archivos que no son texto, 
// como fotos, música o ejecutables, donde el 0 es un dato 
// común y no el final de nada.
*/