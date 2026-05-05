/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:58:01 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 09:58:04 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}

/*
#include <unistd.h>
#include <limits.h>

// ---------------------------------------------------------
// DEPENDENCIA: ft_putchar_fd
// ---------------------------------------------------------
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// ---------------------------------------------------------
// TEST PRINCIPAL
// ---------------------------------------------------------
int main(void)
{
	write(1, "--- TEST ft_putnbr_fd ---\n", 26);

	// Test 1: Número positivo
	ft_putnbr_fd(42, 1);
	write(1, "\n", 1);

	// Test 2: El cero
	ft_putnbr_fd(0, 1);
	write(1, "\n", 1);

	// Test 3: Número negativo
	ft_putnbr_fd(-2026, 1);
	write(1, "\n", 1);

	// Test 4: INT_MIN (El caso más difícil)
	ft_putnbr_fd(INT_MIN, 1);
	write(1, "\n", 1);

	return (0);
}

// =========================================================
// CTO Note: El Descomponedor de Números (ELI5).
// =========================================================
// Esta función es como un niño que está aprendiendo a contar. 
// Si le pides que escriba "123", él sabe que no puede 
// escribirlo de golpe. 
// 
// Entonces decide: "Primero voy a escribir el 12, y luego 
// escribiré el 3". Pero para escribir el 12, piensa: "Primero 
// escribiré el 1 y luego el 2".
// 
// Al final, los va escribiendo en orden según termina de 
// pensar en cada parte.
// 
// Negocio: Es vital para cualquier sistema que necesite dar 
// feedback numérico al usuario (precios, stock, IDs de 
// transacciones) sin depender de librerías externas pesadas.
*/