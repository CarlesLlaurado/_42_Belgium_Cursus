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
