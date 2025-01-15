/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wifons <wifons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:36:23 by wifons            #+#    #+#             */
/*   Updated: 2025/01/13 18:05:28 by wifons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*extract_word(char const *s, size_t *i, char c)
{
	size_t	start;

	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	return (ft_substr(s, start, *i - start));
}

static char	**free_split(char **split, size_t j)
{
	while (j--)
		free(split[j]);
	return (free(split), NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			split[j] = extract_word(s, &i, c);
			if (!split[j++])
				return (free_split(split, j));
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}
