/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:21:39 by ade-woel          #+#    #+#             */
/*   Updated: 2024/10/30 14:28:53 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*search for last occurence of c in the str*/
char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;
	char			*res;

	cc = (char) c;
	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			res = (char *) &s[i];
		i++;
	}
	if (s[i] == cc)
		res = (char *) &s[i];
	return (res);
}
