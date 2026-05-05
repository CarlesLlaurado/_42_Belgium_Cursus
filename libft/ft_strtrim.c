/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:02:36 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 10:02:41 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
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
	while (s[i]) i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	if (!s) return (NULL);
	slen = ft_strlen(s);
	if (start >= slen) return (malloc(1) ? (char *)calloc(1, 1) : NULL);
	if (len > slen - start) len = slen - start;
	sub = malloc(len + 1);
	if (!sub) return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

// ---------------------------------------------------------
// TEST PRINCIPAL
// ---------------------------------------------------------
int main(void)
{
	char *s1 = "   ---Hola Mundo---   ";
	char *set = " -";
	char *res;

	printf("--- TEST ft_strtrim ---\n");

	// Test 1: Limpieza de espacios y guiones
	res = ft_strtrim(s1, set);
	printf("Original: [%s]\n", s1);
	printf("Set:      [%s]\n", set);
	printf("Resultado: [%s]\n", res);
	free(res);

	// Test 2: Todo el string debe ser eliminado
	res = ft_strtrim("aaaaa", "a");
	printf("Vaciado:   [%s]\n", res);
	free(res);

	return (0);
}

// =========================================================
// CTO Note: El Peluquero de Strings (ELI5).
// =========================================================
// Imagina que recibes un paquete que tiene mucho papel de 
// relleno al principio y al final. Tú solo quieres el regalo.
// 
// Esta función:
// 1. Mira desde la izquierda y salta todos los caracteres que 
//    estén en tu "set" (basura).
// 2. Mira desde la derecha y hace lo mismo hacia atrás.
// 3. Cuando sabe dónde empieza y acaba lo importante, 
//    "recorta" esa parte y te la entrega en una caja nueva.
// 
// Negocio: Crucial para limpiar datos de formularios (ej: 
// quitar espacios accidentales en un nombre o email).
*/