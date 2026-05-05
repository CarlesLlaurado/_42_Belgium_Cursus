/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:46:04 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 09:47:43 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

/*
#include<stdio.h>
int main(void)
{
	char s[10] = "CarlesLLL";
	ft_bzero(s, 3);
	int i = 0;
	while (i < 10)
	{
		printf("%d ", (unsigned char)s[i]);
		i++;
	}
}
*/