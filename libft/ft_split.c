/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:58:26 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/04/28 09:58:40 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	if (!s)
		return (0);
	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_get_word(char const *s, char c, int *i)
{
	int		start;
	int		len;

	if (!s)
		return (NULL);
	while (s[*i] == c)
		(*i)++;
	start = *i;
	len = 0;
	while (s[*i] && s[*i] != c)
	{
		(*i)++;
		len++;
	}
	return (ft_substr(s, start, len));
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;
	int		j;

	words = ft_count_words(s, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (j < words)
	{
		result[j] = ft_get_word(s, c, &i);
		if (!result[j])
		{
			while (j-- > 0)
				free(result[j]);
			free(result);
			return (NULL);
		}
		j++;
	}
	result[j] = NULL;
	return (result);
}

/*
#include <stdio.h>
#include <stdlib.h>

// ---------------------------------------------------------
// DEPENDENCIAS (Simuladas para el test)
// ---------------------------------------------------------
size_t	ft_strlen(const char *s)
{
	size_t i = 0;
	while (s[i]) i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	if (!s) return (NULL);
	slen = ft_strlen(s);
	if (start >= slen) return (calloc(1, 1));
	if (len > slen - start) len = slen - start;
	sub = malloc(len + 1);
	if (!sub) return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

// ---------------------------------------------------------
// TEST PRINCIPAL
// ---------------------------------------------------------
int main(void)
{
	char	**result;
	char	*s = "  Lausana  es el  objetivo final  ";
	char	c = ' ';
	int		i = 0;

	printf("--- TEST ft_split ---\n");
	printf("Frase: [%s] | Delimitador: '%c'\n\n", s, c);

	result = ft_split(s, c);
	if (!result)
	{
		printf("Error: Fallo de memoria.\n");
		return (1);
	}

	while (result[i])
	{
		printf("Palabra[%d]: [%s]\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);

	printf("\nResultado: Array liberado correctamente.\n");
	return (0);
}

// =========================================================
// CTO Note: La Cortadora de Embutido (ELI5).
// =========================================================
// Imagina que tienes un fuet largo (el string) y quieres 
// hacer rodajas. El delimitador 'c' es donde quieres cortar.
// 
// Esta función:
// 1. Cuenta cuántas rodajas saldrán (ft_count_words).
// 2. Prepara un plato con huecos para esas rodajas (malloc).
// 3. Corta cada rodaja individualmente (ft_get_word) y la 
//    pone en su sitio del plato.
// 4. Si se queda sin platos limpios a mitad (falla malloc),
//    tira a la basura las rodajas que ya había cortado y
//    limpia la mesa (free).
// 
// Negocio: Es la base para procesar archivos CSV o comandos 
// de usuario ("ls -la -R") donde cada palabra es un argumento.
*/