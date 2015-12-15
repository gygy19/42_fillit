/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 02:38:48 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/10 02:39:24 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "all.h"

void	ft_lstaddendtrix(t_trix **list, t_trix *toadd)
{
	t_trix *tmp;

	if (!(*list)->next)
	{
		tmp = (*list);
		tmp->next = toadd;
	}
	else
	{
		tmp = (*list);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = toadd;
	}
}
