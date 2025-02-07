/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:02:04 by ade-woel          #+#    #+#             */
/*   Updated: 2024/10/30 14:38:47 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*converts a number to a string*/
static int	ft_count(long n, int count)
{
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	if (n == 0)
		count++;
	while (n != 0)
	{
		n = (n / 10);
		count++;
	}
	return (count);
}

static char	*ft_putnbr(long nbr, int count, char *str, int index)
{
	while (index < count)
	{
		str[count - 2] = (nbr % 10) + '0';
		nbr = nbr / 10;
		count--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		count;

	nbr = n;
	count = 1;
	count = ft_count(nbr, count);
	str = malloc(sizeof(char) * count);
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		str = ft_putnbr(-nbr, count, str, 2);
	}
	else
		str = ft_putnbr(nbr, count, str, 1);
	str[count - 1] = '\0';
	return (str);
}
