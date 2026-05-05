/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:56:04 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 09:56:08 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

// ---------------------------------------------------------
// TEST PRINCIPAL
// ---------------------------------------------------------
int main(void)
{
    // Datos con ceros en medio para testear la robustez.
    char s1[] = "abc\0def";
    char s2[] = "abc\0dxf";

    printf("--- TEST ft_memcmp ---\n");

    // Test 1: Idénticos hasta n = 3
    printf("Test 1 (Hasta 3) -> %d\n", ft_memcmp(s1, s2, 3));

    // Test 2: Diferentes en la posición 5 ('e' vs 'x')
    // Aunque haya un \0 antes, memcmp debe llegar hasta allí.
    printf("Test 2 (Hasta 6) -> %d\n", ft_memcmp(s1, s2, 6));

    // Test 3: Idénticos totalmente
    printf("Test 3 (Iguales) -> %d\n", ft_memcmp(s1, s1, 7));

    return (0);
}

// =========================================================
// CTO Note: El Comparador de ADN (ELI5).
// =========================================================
// Es como comparar dos cajas cerradas llenas de cosas. No 
// importa si dentro hay texto, fotos o aire (ceros). 
// 
// Miras el primer objeto de cada caja, si son iguales pasas 
// al segundo, y así hasta 'n' veces. 
// 
// Si encuentras algo diferente, restas sus valores y paras. 
// Si llegas al final de 'n' y todo era igual, devuelves 0.
// 
// Negocio: Se usa para saber si dos archivos (como un PDF o 
// una imagen) son exactamente iguales bit a bit.
*/