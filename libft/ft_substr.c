/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:02:52 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 10:02:55 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

/*
#include <stdio.h>
#include <stdlib.h>

// ---------------------------------------------------------
// DEPENDENCIAS (Para que el test compile solo)
// ---------------------------------------------------------
size_t	ft_strlen(const char *s)
{
	size_t i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	i = 0;
	d = malloc(ft_strlen(s) + 1);
	if (!d) return (NULL);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

// ---------------------------------------------------------
// TEST PRINCIPAL
// ---------------------------------------------------------
int main(void)
{
	char *str = "Hola Mundo";
	char *res;

	printf("--- TEST ft_substr ---\n");

	// Test 1: Caso normal (Extraer "Mundo")
	res = ft_substr(str, 5, 5);
	printf("Test 1 (Normal):   [%s]\n", res);
	free(res);

	// Test 2: 'len' más largo que el string restante
	res = ft_substr(str, 5, 20);
	printf("Test 2 (Len > s):  [%s]\n", res);
	free(res);

	// Test 3: 'start' fuera de rango (Debe dar "")
	res = ft_substr(str, 20, 5);
	printf("Test 3 (Out start): [%s]\n", res);
	free(res);

	return (0);
}

// =========================================================
// CTO Note: El Cortador de Pizza (ELI5).
// =========================================================
// Imagina que tienes una pizza entera ("s"). 
// 
// Esta función te permite llevarte una porción:
// 1. 'start' es donde pones el cuchillo para empezar a cortar.
// 2. 'len' es el tamaño máximo de la porción que quieres.
// 
// Si intentas empezar a cortar donde ya no hay pizza, te damos
// una caja vacía (""). Si pides una porción más grande de lo
// que queda de pizza, solo te damos lo que queda.
// 
// Negocio: Esencial para extraer datos de un texto largo, como
// sacar el "Nombre" de una línea de un archivo de clientes.
*/