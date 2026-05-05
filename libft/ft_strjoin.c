/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:00:08 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 10:00:11 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

/*
#include <stdio.h>
#include <stdlib.h>

// ---------------------------------------------------------
// DEPENDENCIA: ft_strlen (Necesaria para calcular el tamaño)
// ---------------------------------------------------------
size_t	ft_strlen(const char *s)
{
	size_t i = 0;
	while (s[i])
		i++;
	return (i);
}

// ---------------------------------------------------------
// TEST PRINCIPAL
// ---------------------------------------------------------
int main(void)
{
	char *prefijo = "SaaS ";
	char *sufijo = "Lausana";
	char *unido;

	printf("--- TEST ft_strjoin ---\n");

	// 1. Ejecución
	unido = ft_strjoin(prefijo, sufijo);

	// 2. Verificación
	if (!unido)
	{
		printf("Error: Fallo de malloc.\n");
		return (1);
	}

	printf("S1: [%s]\n", prefijo);
	printf("S2: [%s]\n", sufijo);
	printf("Resultado: [%s]\n", unido);

	// 3. Limpieza
	free(unido);
	return (0);
}

// =========================================================
// CTO Note: El Pegamento de Palabras (ELI5).
// =========================================================
// Esta función es como un bote de pegamento. Tienes dos trozos
// de papel con palabras escritas y quieres uno solo.
// 
// Pasos que sigue tu código:
// 1. Mide cuánto miden los dos papeles juntos.
// 2. Crea un papel nuevo lo suficientemente largo (malloc).
// 3. Copia el primer papel, y justo donde termina, empieza
//    a copiar el segundo.
// 4. Pone el punto final (\0) para que C sepa que ahí acaba.
// 
// Negocio: Fundamental para crear mensajes dinámicos, como
// unir "Hola " + "NombreUsuario" para un saludo en una App.
*/