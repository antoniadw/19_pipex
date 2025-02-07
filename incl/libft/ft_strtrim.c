/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woe <ade-woel@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:48:46 by ade-woel          #+#    #+#             */
/*   Updated: 2024/12/09 17:50:50 by ade-woe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issep(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_slen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	ft_start_trim(size_t i, char const *s1, char const *set)
{
	while (ft_issep(s1[i], set))
		i++;
	return (i);
}

static size_t	ft_end_trim(size_t j, char const *s1, char const *set)
{
	while (j > 0 && ft_issep(s1[j], set))
		j--;
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		i;
	size_t		j;
	size_t		k;

	if (!s1 || !set)
		return (NULL);
	i = ft_start_trim(0, s1, set);
	j = ft_end_trim(ft_slen(s1) - 1, s1, set);
	k = 0;
	if (i >= ft_slen(s1))
		return (ft_strdup(""));
	str = malloc(sizeof(char) * ((j - i) + 2));
	if (!str)
		return (NULL);
	while (i <= j)
	{
		str[k] = s1[i];
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}

/*
int main (void)
{
	char s1[] = "lorem ipsum dolor sit amet";
	printf("%s\n", s1);
	char *str = ft_strtrim(s1, "tel");
	printf("%s\n", str);
	return (0);
}
*/