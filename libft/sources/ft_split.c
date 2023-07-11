/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:51:30 by christiansc       #+#    #+#             */
/*   Updated: 2023/04/14 17:22:00 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_split() function eturns an array of strings obtained by splitting
// the string ’s’ using the	character ’c’ as a delimiter.
// The returned array ends with a NULL pointer.

#include "../includes/libft.h"

static int	char_is_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_strs(char const *s, char *c)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (char_is_in_set(s[i], c))
		{
			while (s[i] && char_is_in_set(s[i], c))
				i ++;
		}
		else
		{
			while (s[i] && !char_is_in_set(s[i], c))
				i ++;
			counter ++;
		}
	}
	return (counter);
}

static char	**free_strs(char ***strs, int wc)
{
	int	i;

	i = 0;
	while (i < wc)
		free((*strs)[i]);
	free(*strs);
	return (NULL);
}

char	**split(const char *s, char *c, char **strs, int words)
{
	int	i;
	int	len;
	int	word_count;

	word_count = 0;
	i = 0;
	len = 0;
	while (s[i] && word_count < words)
	{
		while (s[i] && char_is_in_set(s[i], c))
			i ++;
		while (s[i] && !char_is_in_set(s[i], c))
		{
			i ++;
			len ++;
		}
		strs[word_count] = ft_substr(s, i - len, len);
		if (!(strs[word_count]))
			return (free_strs(&strs, word_count));
		len = 0;
		word_count ++;
	}
	return (strs);
}

char	**ft_split(char const *s, char *c)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = ft_calloc(sizeof(char *), (count_strs(s, c) + 1));
	if (!ptr)
		return (NULL);
	ptr[count_strs(s, c)] = 0;
	ptr = split(s, c, ptr, count_strs(s, c));
	return (ptr);
}
