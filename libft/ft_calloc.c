/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:48:07 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 09:48:40 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size != 0 && nmemb > 2147483647 / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// ---------------------------------------------------------
// DEPENDENCIAS: Necesarias para que el test compile solo
// ---------------------------------------------------------
void    ft_bzero(void *s, size_t n)
{
    unsigned char *ptr = s;
    while (n--)
        *ptr++ = 0;
}

// ---------------------------------------------------------
// TEST PRINCIPAL
// ---------------------------------------------------------
int main(void)
{
    int *arr;
    size_t n = 5;
    size_t i = 0;

    printf("--- TEST ft_calloc ---\n");

    // Test 1: Reserva de 5 enteros
    arr = (int *)ft_calloc(n, sizeof(int));
    
    if (!arr)
    {
        printf("Error: Fallo en la reserva.\n");
        return (1);
    }

    // Verificamos que todo esté a 0 (propiedad de calloc)
    printf("Contenido inicial (debe ser todo 0):\n");
    while (i < n)
    {
        printf("arr[%zu] = %d\n", i, arr[i]);
        i++;
    }

    free(arr);
    
    // Test 2: Caso de seguridad (nmemb o size a 0)
    void *ptr2 = ft_calloc(0, 10);
    printf("\nTest 2 (nmemb 0): %s\n", ptr2 ? "Puntero OK" : "NULL");
    free(ptr2);

    return (0);
}

// =========================================================
// CTO Note: El Hotel de Memoria Limpia (ELI5).
// =========================================================
// Reservar memoria con 'malloc' es como alquilar una habitación:
// te la dan pero puede haber basura del inquilino anterior.
// 
// 'ft_calloc' hace dos cosas:
// 1. Calcula cuánto espacio necesitas (n elementos de x tamaño).
// 2. Alquila la habitación y manda a un equipo de limpieza 
//    (ft_bzero) para dejarlo todo brillante y a CERO.
// 
// Negocio: Es la forma más segura de crear arrays. Al empezar 
// todo a cero, evitas que tu programa tome decisiones basadas 
// en "basura" que hubiera antes en la RAM.
*/