/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:45:20 by ade-woel          #+#    #+#             */
/*   Updated: 2024/10/31 10:23:40 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*writes len bytes of value c to the string b*/
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	int				i;

	i = 0;
	tmp = (unsigned char *)b;
	while (len > 0)
	{
		tmp[i] = c;
		i++;
		len--;
	}
	return (b);
}
