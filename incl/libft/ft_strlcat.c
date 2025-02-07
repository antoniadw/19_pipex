/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:11:51 by ade-woel          #+#    #+#             */
/*   Updated: 2024/10/30 16:33:25 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*concatenate two str and always NUL terminate*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize == 0)
		return (src_len);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	i = 0;
	j = dst_len;
	while (src[i] && j < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (src_len + dst_len);
}

/*
#include <stdio.h>
#include <unistd.h>

int main (void)
{
	char dst[50] = "abc";
	char *src = "lorem ipsum dolor sit amet";
	printf("%s\n", dst);
	printf("%s\n", src);
	printf("%zu\n", ft_strlen(dst));
	printf("%zu\n", ft_strlen(src));
	ft_strlcat(dst, src, -2);
	printf("%s\n", dst);
	return (0);
}
*/