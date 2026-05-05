/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:59:51 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 09:59:55 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>

// ---------------------------------------------------------
// FUNCIÓN DE PRUEBA (f)
// ---------------------------------------------------------
// Recibe el puntero al carácter, por lo que puede cambiarlo.
void	test_modify(unsigned int i, char *c)
{
	(void)i; // No usamos el índice en este test, silenciamos el warning
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

// ---------------------------------------------------------
// TEST PRINCIPAL
// ---------------------------------------------------------
int main(void)
{
	// Nota: Usamos un array [] y no un puntero *str = "abc"
	// porque los strings literales no se pueden modificar.
	char str[] = "brussels 2026";

	printf("--- TEST ft_striteri ---\n");
	printf("Antes:  [%s]\n", str);

	// Ejecución: Modifica el string original
	ft_striteri(str, test_modify);

	printf("Después: [%s]\n", str);

	return (0);
}

// =========================================================
// CTO Note: Cirugía estética sin anestesia (ELI5).
// =========================================================
// A diferencia de la anterior (strmapi), aquí no compramos 
// una caja nueva para el resultado.
// 
// Es como si el operario "f" fuera por la fila de letras 
// con un borrador y un rotulador. Si ve una letra que no 
// le gusta, la borra y escribe encima en el mismo papel.
// 
// Al terminar, el papel original ha cambiado. No hay copias.
// 
// Negocio: Extremadamente útil cuando tienes poca memoria o 
// manejas strings gigantes (como el código fuente de una web) 
// y quieres limpiarlos sin duplicar el consumo de RAM.
*/