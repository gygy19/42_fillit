/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_suite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 02:08:38 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/11 03:02:32 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include "libft.h"

int		check_position_2(size_t i, size_t lines, int end, int sharp)
{
	if (i < 22)
	{
		if (lines != 3 && lines != 4)
			return (0);
	}
	else if (end)
	{
		if (lines != 4)
			return (0);
	}
	else if (lines != 4)
		return (0);
	if (sharp != 4)
		return (0);
	return (1);
}
