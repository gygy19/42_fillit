/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 23:34:52 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/06 03:17:08 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include <stdio.h>

int		check_position(char *buf, size_t i)
{
	int tmp;
	int sharp_nbr;

	tmp = 0;
	sharp_nbr = 0;
	while (tmp <= 19)
	{
		if (buf[i] == '#')
		{
			if (buf[i + 1] == '#' || buf[i - 1] == '#'
				|| buf[i + 5] == '#' || buf[i - 5] == '#')
			sharp_nbr++;
		}
		tmp++;
		i++;
	}
	if (sharp_nbr != 4)
		return (0);
	return (1);
}
size_t	check_bloc(char *buf, size_t i)
{
	int tmp;
	int char_nbr;
	int lines;

	tmp = 0;
	char_nbr = 0;
	lines = 0;

	//TODO : CHECK LINES PER BLOC !
	if (!check_position(buf, i))
		return (0);
	while (tmp <= 19)
	{
		if (buf[i] != '\n' && buf[i] != '.'
				&& buf[i] != '#' && buf[i] != '\0')
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
		{
			if (buf[i + 1] == '\n')
				lines++;
			if (buf[i + 2] == '\n')
			{
				if (buf[i + 3] != '.'
						&& buf[i + 3] != '#')
					return (0);
			}
			else if(!buf[i + 2] || buf[i + 2] < 33 || buf[i + 2] == 0)
				return (i + 9999);
			else
				return (0);
		}
		tmp++;
		i++;
	}
	return (i + 1);
}
int		check_all(char *buf)
{
	size_t i;
	size_t bloc_nbr;

	i = 0;
	bloc_nbr = 0;
	while (i < 9999)
	{
		bloc_nbr++;
		i = check_bloc(buf, i);
		//printf("%ld\n", i);
		if (!i || bloc_nbr > 26)
			return (0);
	}
	i = i - 9999;
	//printf("%ld", bloc_nbr);
	/*if (!buf[i - 3] == '\0')
		return (0);*/
	return (1);
}
