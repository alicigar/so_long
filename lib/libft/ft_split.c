/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar <alicigar@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 23:47:26 by alicigar          #+#    #+#             */
/*   Updated: 2025/01/09 23:48:48 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*extract_word(char const *s, char c, size_t *start)
{
	size_t	len;
	char	*word;

	len = 0;
	while (s[*start] && s[*start] == c)
		(*start)++;
	while (s[*start + len] && s[*start + len] != c)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy (word, s + *start, len + 1);
	*start += len;
	return (word);
}

static void	free_array(char **arr, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free (arr[i]);
		i++;
	}
	free (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	size_t	word_count;
	size_t	i;
	size_t	start;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	r = malloc(sizeof(char *) * (word_count + 1));
	if (!r)
		return (NULL);
	i = 0;
	start = 0;
	while (i < word_count)
	{
		r[i] = extract_word(s, c, &start);
		if (!r[i])
		{
			free_array(r, i);
			return (NULL);
		}
		i++;
	}
	r[i] = NULL;
	return (r);
}
