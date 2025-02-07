/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:06:41 by ade-woel          #+#    #+#             */
/*   Updated: 2025/01/21 15:53:56 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count = write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		count += write(fd, "-", 1);
		count += ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		count += ft_putnbr_fd(n / 10, fd);
		count += ft_putnbr_fd(n % 10, fd);
	}
	else
		count += ft_putchar_fd(n + '0', fd);
	if (count < 0)
		return (-1);
	return (count);
}
