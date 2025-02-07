/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:41:18 by ade-woel          #+#    #+#             */
/*   Updated: 2024/10/30 14:04:56 by ade-woel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*temp;

	if (!lst)
		return (0);
	size = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}
