/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 05:39:43 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/15 03:48:25 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include "libft.h"

short		size_tab(short size_byte_tab)
{
	short short_byte_max;
	short size;

	short_byte_max = 16384;/*first byte actived*/
	size = 0;
	while (size_byte_tab < short_byte_max)
	{
		size_byte_tab = size_byte_tab * 2;
		size++;
	}
	return (size);
}

t_trix		*reset_all_form(t_trix *trix)
{
	short id;
	short line;
	
	id = 0;
	while (id < trix->nbr)
	{
		line = 0;
		while (line < trix->size[id])
		{
			if (line >= trix->old_size[id])
				trix->form[id][line] = 0;
			else
				trix->form[id][line] = trix->old_form[id][line];
			line++;
		}
		trix->size[id] = trix->old_size[id];
		id++;
	}
	return (trix);
}

