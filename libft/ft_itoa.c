/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:50:55 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 09:51:01 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = ft_numlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (len-- > (n < 0))
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// ---------------------------------------------------------
// TEST PRINCIPAL
// ---------------------------------------------------------
int main(void)
{
	char *res;

	printf("--- TEST ft_itoa ---\n");

	// Test 1: El número cero
	res = ft_itoa(0);
	printf("Test 1 (Cero):      [%s]\n", res);
	free(res);

	// Test 2: Un número positivo estándar
	res = ft_itoa(2026);
	printf("Test 2 (Positivo):  [%s]\n", res);
	free(res);

	// Test 3: Un número negativo estándar
	res = ft_itoa(-42);
	printf("Test 3 (Negativo):  [%s]\n", res);
	free(res);

	// Test 4: El valor máximo de un int (2147483647)
	res = ft_itoa(INT_MAX);
	printf("Test 4 (INT_MAX):   [%s]\n", res);
	free(res);

	// Test 5: EL BOSS FINAL (INT_MIN: -2147483648)
	res = ft_itoa(INT_MIN);
	printf("Test 5 (INT_MIN):   [%s]\n", res);
	free(res);

	return (0);
}

// =========================================================
// CTO Note: La Impresora de Números (ELI5).
// =========================================================
// El ordenador no sabe que el número 123 se escribe con los 
// dibujos '1', '2' y '3'. Para él es solo voltaje en un chip.
// 
// Esta función:
// 1. Mide cuánto espacio ocupará el número (ft_numlen).
// 2. Reserva un trozo de memoria para el texto (malloc).
// 3. Va "pelando" el número desde el final usando el resto (%) 
//    y convirtiendo cada cifra en su dibujo ASCII (+ '0').
// 4. Si el número era negativo, le pone la raya '-' al principio.
// 
// Negocio: Fundamental para mostrar puntuaciones, precios o 
// contadores en una interfaz de usuario. Sin esto, solo 
// tendrías datos invisibles.
*/