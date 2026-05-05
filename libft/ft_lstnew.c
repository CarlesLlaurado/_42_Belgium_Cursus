/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:54:44 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 09:54:49 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/*
#include <stdio.h>
#include <stdlib.h>

// ---------------------------------------------------------
// TEST PRINCIPAL
// ---------------------------------------------------------
int main(void)
{
	t_list	*nuevo_nodo;
	char	*contenido = "Mi primer SaaS en Lausana";

	printf("--- TEST ft_lstnew ---\n");

	// 1. Crear el nodo
	nuevo_nodo = ft_lstnew(contenido);

	// 2. Verificar
	if (!nuevo_nodo)
	{
		printf("Error: Fallo de malloc.\n");
		return (1);
	}

	printf("Contenido del nodo: [%s]\n", (char *)nuevo_nodo->content);
	
	if (nuevo_nodo->next == NULL)
		printf("Siguiente nodo: [NULL] (Correcto)\n");
	else
		printf("Error: next no es NULL.\n");

	// 3. Limpieza
	free(nuevo_nodo);
	return (0);
}

// =========================================================
// CTO Note: La Flexibilidad del "void *" (ELI5).
// =========================================================
// ¿Te has fijado en que 'content' es un 'void *'?
// En C, esto es un "comodín". Significa que tu lista es 
// genérica: hoy puede guardar frases, mañana números y 
// pasado mañana fotos de coches clásicos.
// 
// Negocio: Como emprendedor, esto te permite reutilizar el 
// mismo código de listas para cualquier parte de tu App, 
// ahorrando horas de desarrollo. Es la base de la 
// programación modular.
*/