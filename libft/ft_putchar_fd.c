/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:57:04 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 09:57:07 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
#include <unistd.h>
#include <fcntl.h> // Para open()

// ---------------------------------------------------------
// TEST PRINCIPAL
// ---------------------------------------------------------
int main(void)
{
	// Test 1: Escribir en la salida estándar (Terminal)
	ft_putchar_fd('C', 1);
	ft_putchar_fd('T', 1);
	ft_putchar_fd('O', 1);
	ft_putchar_fd('\n', 1);

	// Test 2: Escribir en el canal de errores
	// (En la terminal se verá igual, pero es otra "ventanilla")
	ft_putchar_fd('!', 2);
	ft_putchar_fd('\n', 2);

	// Test 3: Escribir en un archivo real
	int fd = open("test_output.txt", O_WRONLY | O_CREAT, 0644);
	if (fd != -1)
	{
		ft_putchar_fd('X', fd);
		close(fd);
	}

	return (0);
}

// =========================================================
// CTO Note: El Mensajero de una Sola Letra (ELI5).
// =========================================================
// Esta función es como un mensajero que solo puede llevar 
// una letra cada vez. 
// 
// Tú le das la letra ('c') y el número de la oficina a la 
// que debe ir ('fd'). El mensajero corre, entrega la letra 
// y vuelve. 
// 
// Negocio: Es vital para el control total. Si quieres crear 
// un archivo de logs de tu empresa para saber qué ha fallado, 
// usarás esta base para escribir los datos en un archivo 
// oculto en lugar de llenar la pantalla del cliente.
*/