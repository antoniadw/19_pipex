/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:54:59 by ade-woel          #+#    #+#             */
/*   Updated: 2024/10/30 14:34:56 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*searches for a substring inside a string*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == 0)
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] && i + j < len)
		{
			j++;
			if (needle[j] == 0)
				return ((char *) haystack + i);
		}
		i++;
		j = 0;
	}
	return (0);
}

/*
#include <stdio.h> 

int main (void)
{
	const char *h = "Hello world";
	const char *n = "world";
	size_t	len = 12;
	printf("%sn", ft_strnstr(h, n, len));
	return (0);
}
*/