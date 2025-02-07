/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:36:08 by ade-woel          #+#    #+#             */
/*   Updated: 2024/11/05 11:50:43 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*same as memcpy but non destructive*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp_dst;
	const char	*tmp_src;

	if (!dst && !src)
		return (NULL);
	tmp_dst = (char *) dst;
	tmp_src = (const char *) src;
	if (tmp_dst < tmp_src || tmp_dst >= tmp_src + len)
	{
		while (len--)
			*tmp_dst++ = *tmp_src++;
	}
	else
	{
		tmp_dst += len;
		tmp_src += len;
		while (len--)
			*(--tmp_dst) = *(--tmp_src);
	}
	return (dst);
}
