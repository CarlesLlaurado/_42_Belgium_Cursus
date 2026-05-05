/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:01:02 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 10:01:07 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*
#include <stdio.h>
#include <stdlib.h>

// ---------------------------------------------------------
// DEPENDENCIA: ft_strlen
// ---------------------------------------------------------
size_t	ft_strlen(const char *s)
{
	size_t i = 0;
	while (s[i]) i++;
	return (i);
}

// ---------------------------------------------------------
// FUNCIÓN DE PRUEBA (f)
// ---------------------------------------------------------
// Si el índice es par, convierte a mayúsculas (si es minúscula).
char	test_transform(unsigned int i, char c)
{
	if (i % 2 == 0 && (c >= 'a' && c <= 'z'))
		return (c - 32);
	return (c);
}

// ---------------------------------------------------------
// TEST PRINCIPAL
// ---------------------------------------------------------
int main(void)
{
	char *str = "holamundo";
	char *res;

	printf("--- TEST ft_strmapi ---\n");

	// Ejecución aplicando nuestra función de prueba
	res = ft_strmapi(str, test_transform);

	if (!res)
	{
		printf("Error: Fallo de malloc.\n");
		return (1);
	}

	printf("Original:  [%s]\n", str);
	printf("Resultado: [%s] (Mayúsculas en índice par)\n", res);

	free(res);
	return (0);
}

// =========================================================
// CTO Note: La Fábrica de Transformación (ELI5).
// =========================================================
// Imagina una cinta transportadora donde pasan letras. 
// Al lado de la cinta hay un operario ("f").
// 
// Por cada letra que pasa, el operario mira dos cosas:
// 1. Qué letra es (char).
// 2. En qué posición de la fila viene (index).
// 
// El operario hace algo con esa letra y la pone en una 
// caja nueva ("result"). Al final, tienes una copia de 
// la fila original pero con los cambios del operario.
// 
// Negocio: Útil para encriptación simple o para formatear 
// textos (ej: poner en negrita cada tres palabras o 
// alternar estilos visuales).
*/