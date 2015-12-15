/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:28:05 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/15 02:42:12 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include "bloc.h"
#include "libft.h"

t_trix		*replace_bloc(t_trix *list)
{
	char *tmp;

	tmp = NULL;
	if (list->all_char[0] == '.' || list->all_char[0] == '#')
		tmp = tetrixcmp(list->all_char, 0, 0);
	list->tetrix_char = tmp;
	return (list);
}

t_trix		*set_inbytes(t_trix *list)
{
	list = replace_bloc(list);
	list->next = NULL;
	return (list);
}

t_trix		*do_struct(char *buf, size_t start)
{
	size_t	end;
	char	*tmp;
	size_t	tmp_i;
	t_trix	*tmp_list;

	tmp = ft_strnew(21);
	tmp_list = malloc(sizeof(t_trix));
	tmp_i = 0;
	if (start > 9999)
		start = start - 9998;
	start = start - 21;
	end = start + 19;
	while (start != end)
	{
		tmp[tmp_i] = buf[start];
		start++;
		tmp_i++;
	}
	tmp_list->all_char = tmp;
	tmp_list = set_inbytes(tmp_list);
	return (tmp_list);
}
