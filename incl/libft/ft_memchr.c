/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:26:03 by ade-woel          #+#    #+#             */
/*   Updated: 2024/10/30 16:13:54 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*similar to strchr but works with byte string (void *) over n bytes*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*str;
	size_t			i;

	i = 0;
	uc = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == uc)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
