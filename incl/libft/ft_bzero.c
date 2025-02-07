/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:08:10 by ade-woel          #+#    #+#             */
/*   Updated: 2024/10/30 14:25:03 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*writes n bytes of 0 to the string s*/
void	ft_bzero(void *s, size_t n)
{
	char	*tmp;

	tmp = (char *)s;
	while (n > 0)
	{
		*(tmp++) = 0;
		n--;
	}
}

/*
int main (int argc, char **argv)
{
	(void)argc;
	printf("%s\n", argv[1]);
	ft_bzero(argv[1], 5);	
	printf("%s\n", argv[1]);
	return (0);
}
*/