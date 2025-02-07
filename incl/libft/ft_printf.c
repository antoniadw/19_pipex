/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:43:19 by ade-woe           #+#    #+#             */
/*   Updated: 2025/01/21 15:53:29 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_put_ptr(uintptr_t nbr)
{
	char	*chars;
	int		count;

	chars = "0123456789abcdef";
	count = 0;
	count += ft_putstr_fd("0x", 1);
	if (nbr >= 16)
	{
		count += ft_put_ptr(nbr / 16);
		count += ft_put_ptr(nbr % 16);
	}
	else
		count += ft_putchar_fd(chars[nbr], 1);
	if (count < 0)
		return (-1);
	return (count);
}

static int	ft_put_unbr(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
	{
		count += ft_put_unbr(nbr / 10);
		count += ft_put_unbr(nbr % 10);
	}
	else
		count += ft_putchar_fd((nbr + '0'), 1);
	if (count < 0)
		return (-1);
	return (count);
}

static int	ft_put_hex(char *chars, unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_put_hex(chars, nbr / 16);
		count += ft_put_hex(chars, nbr % 16);
	}
	else
		count += ft_putchar_fd(chars[nbr], 1);
	if (count < 0)
		return (-1);
	return (count);
}

static int	ft_check_spec(const char spec, va_list args)
{
	int		count;

	count = 0;
	if (spec == 'c')
		count += ft_putchar_fd(va_arg(args, int), 1);
	if (spec == 's')
		count += ft_putstr_fd(va_arg(args, char *), 1);
	if (spec == 'p')
		count += ft_put_ptr(va_arg(args, uintptr_t));
	if (spec == 'd' || spec == 'i')
		count += ft_putnbr_fd(va_arg(args, int), 1);
	if (spec == 'u')
		count += ft_put_unbr(va_arg(args, unsigned int));
	if (spec == 'x')
		count += ft_put_hex("0123456789abcdef", va_arg(args, unsigned int));
	if (spec == 'X')
		count += ft_put_hex("0123456789ABCDEF", va_arg(args, unsigned int));
	if (spec == '%')
		return (write(1, "%", 1));
	return (count);
}

int	ft_printf(const char *str, ...)
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
			count += ft_check_spec(str[i], args);
		}
		else
			count += ft_putchar_fd(str[i], 1);
		i++;
	}
	if (count < 0)
		return (-1);
	va_end (args);
	return (count);
}
