/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:43:19 by ade-woe           #+#    #+#             */
/*   Updated: 2025/02/04 14:28:59 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_put_ptr(uintptr_t nbr, int fd)
{
	char	*chars;
	int		count;

	chars = "0123456789abcdef";
	count = 0;
	count += ft_putstr_fd("0x", fd);
	if (nbr >= 16)
	{
		count += ft_put_ptr(nbr / 16, fd);
		count += ft_put_ptr(nbr % 16, fd);
	}
	else
		count += ft_putchar_fd(chars[nbr], fd);
	if (count < 0)
		return (-1);
	return (count);
}

static int	ft_put_unbr(unsigned int nbr, int fd)
{
	int	count;

	count = 0;
	if (nbr > 9)
	{
		count += ft_put_unbr(nbr / 10, fd);
		count += ft_put_unbr(nbr % 10, fd);
	}
	else
		count += ft_putchar_fd((nbr + '0'), fd);
	if (count < 0)
		return (-1);
	return (count);
}

static int	ft_put_hex(char *chars, unsigned int nbr, int fd)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_put_hex(chars, nbr / 16, fd);
		count += ft_put_hex(chars, nbr % 16, fd);
	}
	else
		count += ft_putchar_fd(chars[nbr], fd);
	if (count < 0)
		return (-1);
	return (count);
}

static int	ft_check_spec(int fd, const char spec, va_list args)
{
	int		count;

	count = 0;
	if (spec == 'c')
		count += ft_putchar_fd(va_arg(args, int), fd);
	if (spec == 's')
		count += ft_putstr_fd(va_arg(args, char *), fd);
	if (spec == 'p')
		count += ft_put_ptr(va_arg(args, uintptr_t), fd);
	if (spec == 'd' || spec == 'i')
		count += ft_putnbr_fd(va_arg(args, int), fd);
	if (spec == 'u')
		count += ft_put_unbr(va_arg(args, unsigned int), fd);
	if (spec == 'x')
		count += ft_put_hex("0123456789abcdef", va_arg(args, unsigned int), fd);
	if (spec == 'X')
		count += ft_put_hex("0123456789ABCDEF", va_arg(args, unsigned int), fd);
	if (spec == '%')
		return (write(fd, "%", 1));
	return (count);
}

int	ft_dprintf(int fd, const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start (args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_check_spec(fd, str[i], args);
		}
		else
			count += ft_putchar_fd(str[i], fd);
		i++;
	}
	if (count < 0)
		return (-1);
	va_end (args);
	return (count);
}
