/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:16:11 by ade-woel          #+#    #+#             */
/*   Updated: 2024/10/30 14:25:50 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*copies max n bytes from src to dst*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	int				i;

	if (dst == 0 && src == 0)
		return (dst);
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned char *) src;
	i = 0;
	while (n > 0)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
		n--;
	}
	return (dst);
}
