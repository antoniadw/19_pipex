/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:38:15 by ade-woel          #+#    #+#             */
/*   Updated: 2024/10/30 14:37:48 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*return a substr of s*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (len > 0)
	{
		str[i] = s[start + i];
		i++;
		len--;
	}
	str [i] = '\0';
	return (str);
}
/*
int main (void)
{
	char const *s = "Hello les copains";
	unsigned int start = 3;
	size_t len = 5;
	char *str = ft_substr(s, start, len);
	printf("%sn", str);
	return (0);
}
*/