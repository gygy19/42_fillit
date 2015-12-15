/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 23:16:26 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/15 04:10:18 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

short		possible_fixed(t_trix *all_trix, short id, short dir)
{
	short bloc;
	short line;

	bloc = 0;
	while (bloc < all_trix->nbr)
	{
		if (bloc == id)
			break;
		line = 0;
		while (line < all_trix->size[id])
		{
			if (all_trix->size[bloc] >= line)
				if (all_trix->form[bloc][line] & (dir != 0
					? (all_trix->form[id][line] / dir) : all_trix->form[id][line]))
				{
					if (all_trix->size_tab & (dir != 0
						? (all_trix->form[id][line] / dir) : all_trix->form[id][line]))
						return (3);
					return (0);
				}
			line++;
		}
		bloc++;
	}
	return (1);
}

void		right(t_trix *all_trix, short id)
{
	int line;

	line = 0;
	while (line < all_trix->size[id])
	{
		all_trix->form[id][line] /= 2;
		line++;
	}
}

void		move_down_bloc(t_trix *all_trix, short id)
{
	short new_line;
	short *new;
	short i;

	new = (short*)malloc(sizeof(short));
	new_line = 0;
	new[0] = new_line;
	i = 0;
	while (i < all_trix->size[id])
	{
		new[i + 1] = all_trix->form[id][i];
		i++;
	}
	all_trix->form[id] = new;
	all_trix->size[id]++;
}
