/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:32:41 by ade-woel          #+#    #+#             */
/*   Updated: 2024/10/30 16:36:27 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*compares n characters in s1 and s2*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (c < n && s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
		c++;
	}
	if (c == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>

int main (void)
{
	printf("%d", ft_strncmp("abcdef", "abc\375xx", 3));
	return (0);
}
*/