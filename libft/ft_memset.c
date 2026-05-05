/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:56:46 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 09:56:54 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*
#include <stdio.h>
int main()
{
    char str[50] = "My name is Carles Llauradó";
    printf("\nBefore memset(): %s\n", str);

    ft_memset(str, '.', 8*sizeof(char));

    printf("After memset():  %s", str);
    return 0;
}
*/