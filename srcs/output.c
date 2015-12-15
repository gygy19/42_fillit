/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 08:33:41 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/15 08:33:44 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include "libft.h"

void	put_trix(short *lines, short size, short nbr_line)
{
	short start;
	char c;
	short af;
	short line_id;
	
	start = 16384;
	c = 'A';
	while (start > size)
	{
		af = 0;
		line_id = 0;
		while (line_id < nbr_line)
		{
			if (lines[line_id] & start)
			{
				ft_putchar(c + line_id);
				af = 1;
				break;
			}
			line_id++;
		}
		if (!af)
			ft_putchar('.');
		start = start / 2;
	}
}

short	*all_line(t_trix *all_bloc, short line_cible)
{
	short i;
	short *result;

	i = 0;
	result = malloc(sizeof(short*) * all_bloc->nbr);
	while (i < all_bloc->nbr)
	{
		if ((all_bloc->size[i] - 1) >= line_cible)
		{
			result[i] = all_bloc->form[i][line_cible];
		}
		else
			result[i] = 0;
		i++;
	}
	return (result);
}

short	nbr_all_line(t_trix *all_bloc, short line_cible)
{
	short i;
	short nbr;
	
	i = 0;
	nbr = 0;
	while (i < all_bloc->nbr)
	{
		if ((all_bloc->size[i] - 1) >= line_cible)
			nbr++;
		i++;
	}
	return (nbr);
}

void	put_tab(t_trix *final)
{
	int i;
	short size;
	short nbr_line;

	i = 0;
	size = size_tab(final->size_tab);
	while (i <= size)
	{
		nbr_line = nbr_all_line(final, i);
		if (nbr_line)
		{
			put_trix(all_line(final, i), final->size_tab / 2, final->nbr);
			ft_putchar('\n');
		}
		i++;	
	}
}
