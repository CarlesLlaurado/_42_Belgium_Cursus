/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:58:16 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 09:58:19 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

/*
#include <unistd.h>
#include <stdio.h>

// ---------------------------------------------------------
// DEPENDENCIA: ft_strlen (Necesaria para medir el string)
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
	char *mensaje = "Bienvenido a Bruselas, Carles.\n";

	printf("--- TEST ft_putstr_fd ---\n");

	// Test 1: Salida estándar (Pantalla)
	ft_putstr_fd(mensaje, 1);

	// Test 2: Salida de error (Se verá igual, pero es el canal 2)
	ft_putstr_fd("Error log: Sistema operativo listo.\n", 2);

	return (0);
}

// =========================================================
// CTO Note: El Camión de Mudanzas (ELI5).
// =========================================================
// Si ft_putchar era un mensajero en bicicleta con un sobre,
// ft_putstr es un camión de mudanzas.
// 
// No va y vuelve por cada letra. Carga todo el string ("s"), 
// mide cuánto ocupa (ft_strlen) y lo entrega de golpe en 
// la dirección indicada (fd).
// 
// Negocio: Es la función que usarás para imprimir logs de 
// actividad, confirmar transacciones o mostrar menús 
// enteros en la interfaz de tu SaaS.
*/