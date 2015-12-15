/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 23:34:52 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/15 02:38:58 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include "libft.h"

int		check_sharp(char *buf, size_t i, int tmp, size_t sharp_nbr)
{
	short *array;

	array = malloc(sizeof(short) * 4);
	while (tmp <= 19)
	{
		if (buf[i] == '#')
		{
			array[sharp_nbr] = i;
			sharp_nbr++;
		}
		tmp++;
		i++;
	}
	if (buf[array[0] + 5] == '#' || buf[array[0] + 1] == '#')
		if (buf[array[1] + 5] == '#' || buf[array[1] + 1] == '#'
			|| buf[array[1] + 4] == '#')
			if (buf[array[2] + 5] == '#' || buf[array[2] + 1] == '#'
				|| buf[array[2] + 4] == '#' || buf[array[2] + 3] == '#')
				return (1);
	return (0);
}

int		check_position(char *buf, size_t i, int tmp, int lines)
{
	int sharp_nbr;
	int end;

	end = 0;
	if (!check_sharp(buf, i, 0, 0))
		return (0);
	sharp_nbr = 0;
	while (tmp <= 19)
	{
		if (buf[i] == '\n')
			lines++;
		if (buf[i] == '#')
			sharp_nbr++;
		if (buf[i] == '\0' || buf[i + 1] == '\0')
			end = 1;
		tmp++;
		i++;
	}
	return (check_position_2(i, lines, end, sharp_nbr) ? 1 : 0);
}

size_t	check_nextbloc(char *buf, size_t i)
{
	if (buf[i + 1] != '\n')
		return (0);
	if (buf[i] != '.' && buf[i] != '#')
		return (0);
	if (i < 22)
		if (buf[i + 1] == '\n')
			if (buf[i + 3] != '.' && buf[i + 3] != '#'
				&& buf[i + 3] != '\0')
				return (0);
	if (buf[i + 2] == '\n')
	{
		if (buf[i + 3] != '.'
				&& buf[i + 3] != '#')
			return (0);
	}
	else if (!buf[i + 2] || buf[i + 2] < 33 || buf[i + 2] == 0)
		return (i + 9999);
	else
		return (0);
	return (i);
}

size_t	check_bloc(char *buf, size_t i)
{
	int tmp;
	int char_nbr;

	tmp = 0;
	char_nbr = 0;
	if (!check_position(buf, i, 0, 0))
		return (0);
	while (tmp <= 19 && i < 9999)
	{
		if (buf[i] != '\n' && buf[i] != '.' && buf[i] != '#' && buf[i] != '\0')
			return (0);
		if (tmp < 19)
		{
			char_nbr++;
			if (char_nbr > 5)
				return (0);
			if (buf[i] == '\n')
				char_nbr = 0;
		}
		if (tmp == 18)
			i = check_nextbloc(buf, i);
		tmp++;
		i++;
	}
	return (i + 1);
}

int		check_all(char *buf)
{
	size_t	i;
	size_t	bloc_nbr;
	t_trix	*bloc;
	size_t	first;

	i = 0;
	first = 0;
	bloc = malloc(sizeof(t_trix));
	bloc->next = NULL;
	bloc_nbr = 0;
	while (i < 9999)
	{
		bloc_nbr++;
		i = check_bloc(buf, i);
		if (!i || bloc_nbr > 26)
			return (0);
		ft_lstaddendtrix(&bloc, do_struct(buf, i));
	}
	bloc = bloc->next;
	do_struct_bytes(bloc, bloc_nbr, 0, 0);
	return (1);
}
