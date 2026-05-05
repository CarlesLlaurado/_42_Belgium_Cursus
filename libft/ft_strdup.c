/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:59:37 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 09:59:42 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*
#include <stdio.h>
#include <stdlib.h>

// ---------------------------------------------------------
// DEPENDENCIA: ft_strlen (Necesaria para medir el original)
// ---------------------------------------------------------
size_t	ft_strlen(const char *s)
{
	size_t	i = 0;
	while (s[i])
		i++;
	return (i);
}

// ---------------------------------------------------------
// TEST PRINCIPAL
// ---------------------------------------------------------
int main(void)
{
	char *original = "Copia este String";
	char *duplicado;

	printf("--- TEST ft_strdup ---\n");

	// 1. Ejecución
	duplicado = ft_strdup(original);

	// 2. Verificación de éxito
	if (!duplicado)
	{
		printf("Error: Fallo de memoria.\n");
		return (1);
	}

	// 3. Comprobación de datos y direcciones
	printf("Original:   %s (Dir: %p)\n", original, (void *)original);
	printf("Duplicado:  %s (Dir: %p)\n", duplicado, (void *)duplicado);

	if (original != duplicado)
		printf("\nResultado: ¡Éxito! Son copias en lugares distintos.\n");

	free(duplicado);
	return (0);
}

// =========================================================
// CTO Note: La Fotocopiadora de Memoria (ELI5).
// =========================================================
// Imagina que tienes un papel con un mensaje. Si se lo das 
// a alguien, lo pierdes. Si lo fotocopias, ahora hay dos.
// 
// 'ft_strdup' hace exactamente eso:
// 1. Mide el papel original (ft_strlen).
// 2. Compra un papel nuevo del mismo tamaño (malloc).
// 3. Escribe el mismo mensaje en el papel nuevo.
// 
// Negocio: Es vital cuando quieres modificar un texto 
// (como un nombre de usuario) sin destruir el dato original 
// que tenías guardado en la base de datos.
*/