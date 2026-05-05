/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:57:40 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 09:57:46 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

/*
#include <unistd.h>
#include <stdio.h>

// ---------------------------------------------------------
// DEPENDENCIA: ft_strlen
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
	printf("--- TEST ft_putendl_fd ---\n");

	// Test: Imprimir dos líneas seguidas
	// Si funciona, aparecerán en líneas distintas sin añadir \n manual
	ft_putendl_fd("Primera linea: Objetivo Lausana", 1);
	ft_putendl_fd("Segunda linea: Enero 2026", 1);

	return (0);
}

// =========================================================
// CTO Note: El Mensaje con "Enter" (ELI5).
// =========================================================
// Imagina que estás escribiendo en una máquina de escribir antigua.
// 
// 1. Escribes la frase letra a letra o palabra a palabra.
// 2. Al terminar, golpeas la palanca para que el rodillo 
//    baje y el carro vuelva al principio.
// 
// Esta función hace exactamente eso: escribe tu texto y 
// automáticamente añade el "golpe de palanca" ('\n').
// 
// Negocio: Es la función estándar para escribir en consola 
// o en archivos de texto donde cada dato debe ir en su 
// propia fila (como una lista de precios o un registro de errores).
*/