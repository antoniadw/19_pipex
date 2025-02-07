/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:01:03 by ade-woel          #+#    #+#             */
/*   Updated: 2024/12/12 11:46:11 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			count++;
		if (s[i] != c && (i > 0 && s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*word_dup(const char *s, int start, int end)
{
	char	*word;
	int		j;

	j = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
		word[j++] = s[start++];
	word[j] = '\0';
	return (word);
}

static char	**ft_free(char **tab, size_t k)
{
	while (k-- > 0)
	{
		free(tab[k]);
		tab[k] = NULL;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

static char	**fill_words(size_t size, char **res, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	end = 0;
	while (i < size)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		res[i] = word_dup(s, start, end);
		if (!res[i])
			return (ft_free(res, i));
		start = end;
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	size;

	if (!s)
		return (NULL);
	size = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	result = fill_words(size, result, s, c);
	if (!result)
		return (NULL);
	return (result);
}
/* 
#include <stdio.h>

int main (int argc, char **argv)
{
	char **result;
	int i = 0;

	result = ft_split(argv[1], 'w');
	while (result[i])
	{
		printf("%s\n", result[i]);
		free(result[i]);
		i++;
	}
}
*/