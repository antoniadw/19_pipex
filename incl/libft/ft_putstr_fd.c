/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woe <ade-woel@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:05:34 by ade-woel          #+#    #+#             */
/*   Updated: 2024/12/09 17:37:13 by ade-woe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (write(fd, "(null)", 6));
	else
		return (write(fd, s, ft_strlen(s)));
}
