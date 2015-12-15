/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_struct_bytes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 05:44:18 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/15 05:46:01 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include "libft.h"

short	get_lines_bytes(char *line, int i_2)
{
	short max;
	short result;

	max = 16384;
	result = 0;
	while (line[i_2] != '\n' && line[i_2] != '\0')
	{
		if (line[i_2] == '#')
			result += max;
		max /= 2;
		i_2++;
	}
	return (result);
}

int		height(char *bloc)
{
	int i;
	int lines;

	i = 0;
	lines = 0;
	while (bloc[i])
	{
		if (bloc[i] == '\n')
			lines++;
		i++;
	}
	return (lines);
}

void	to_resolve(t_trix *to_resolve, short **form, size_t bloc_nbr)
{
	to_resolve->form = form;
	to_resolve->nbr = bloc_nbr;
	to_resolve->size_tab = 8192;
	to_resolve->old_form = (short **)malloc(sizeof(short*) * bloc_nbr);
	to_resolve->old_size = (short *)malloc(sizeof(short) * bloc_nbr);
	int bloc;
	int line;

	bloc = 0;
	while (bloc < (int)bloc_nbr)
	{
		line = 0;
		to_resolve->old_form[bloc] = (short *)malloc(sizeof(short) * to_resolve->size[bloc]);
		while (line < to_resolve->size[bloc])
		{
			to_resolve->old_form[bloc][line] = to_resolve->form[bloc][line];
			line++;
		}
		to_resolve->old_size[bloc] = to_resolve->size[bloc]; 
		bloc++;
	}
	resolver_of_trix(to_resolve);
	put_tab(to_resolve);
}

void	do_struct_bytes(t_trix *bloc, size_t bloc_nbr, size_t i, size_t lines)
{
	short	**form;
	t_trix	*new_struct;
	size_t	i_2;

	form = (short **)malloc(sizeof(short*) * bloc_nbr);
	new_struct = (t_trix *)malloc(sizeof(t_trix));
	new_struct->size = (short*)malloc(sizeof(short) * bloc_nbr);
	while (bloc && !(i_2 = 0))
	{
		lines = 0;
		form[i] = (short*)malloc(sizeof(short) * height(bloc->tetrix_char));
		while (bloc->tetrix_char[i_2])
		{
			if (!i_2)
				form[i][lines] = get_lines_bytes(bloc->tetrix_char, i_2);
			if (bloc->tetrix_char[i_2] == '\n' && (lines = lines + 1))
				form[i][lines] = get_lines_bytes(bloc->tetrix_char, i_2 + 1);
			i_2++;
		}
		new_struct->size[i] = (lines + 1);
		bloc = bloc->next;
		i++;
	}
	to_resolve(new_struct, form, bloc_nbr);
}
