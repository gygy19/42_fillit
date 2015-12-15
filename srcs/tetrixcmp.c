/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrixcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 04:51:11 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/15 02:36:21 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include "bloc.h"
#include "libft.h"

char	*start_cmp_4(char *bloc_cleaned)
{
	if (!(ft_strcmp(bloc_cleaned, bloc_17_0)))
		bloc_cleaned = ".#\n##\n.#";
	if (!(ft_strcmp(bloc_cleaned, bloc_18_0)))
		bloc_cleaned = ".#\n##\n#";
	if (!(ft_strcmp(bloc_cleaned, bloc_19_0)))
		bloc_cleaned = ".#.\n###";
	if (!(ft_strcmp(bloc_cleaned, bloc_20_0)))
		bloc_cleaned = "##\n#\n#";
	if (!(ft_strcmp(bloc_cleaned, bloc_21_0)))
		bloc_cleaned = "##\n#\n#";
	if (!(ft_strcmp(bloc_cleaned, bloc_22_0)))
		bloc_cleaned = "##\n.#\n.#";
	if (!(ft_strcmp(bloc_cleaned, bloc_23_0)))
		bloc_cleaned = "##\n.#\n.#";
	if (!(ft_strcmp(bloc_cleaned, bloc_24_0)))
		bloc_cleaned = ".#.\n###";
	if (!(ft_strcmp(bloc_cleaned, bloc_25_0)))
		bloc_cleaned = ".#\n##\n.#";
	if (!(ft_strcmp(bloc_cleaned, bloc_26_0)))
		bloc_cleaned = ".#\n##\n.#";
	return ((bloc_cleaned = start_cmp_5(bloc_cleaned)));
}

char	*start_cmp_3(char *bloc_cleaned)
{
	if (!(ft_strcmp(bloc_cleaned, bloc_10_0)))
		bloc_cleaned = "#\n##\n.#";
	if (!(ft_strcmp(bloc_cleaned, bloc_10_1)))
		bloc_cleaned = "#\n##\n.#";
	if (!(ft_strcmp(bloc_cleaned, bloc_10_2)))
		bloc_cleaned = "#\n##\n.#";
	if (!(ft_strcmp(bloc_cleaned, bloc_11_0)))
		bloc_cleaned = ".##\n##";
	if (!(ft_strcmp(bloc_cleaned, bloc_11_1)))
		bloc_cleaned = ".##\n##";
	if (!(ft_strcmp(bloc_cleaned, bloc_12_0)))
		bloc_cleaned = "##\n.#\n.#";
	if (!(ft_strcmp(bloc_cleaned, bloc_13_0)))
		bloc_cleaned = "#\n###";
	if (!(ft_strcmp(bloc_cleaned, bloc_14_0)))
		bloc_cleaned = "#\n##\n#";
	if (!(ft_strcmp(bloc_cleaned, bloc_15_0)))
		bloc_cleaned = "..#\n###";
	if (!(ft_strcmp(bloc_cleaned, bloc_16_0)))
		bloc_cleaned = "##\n#\n#";
	return ((bloc_cleaned = start_cmp_4(bloc_cleaned)));
}

char	*start_cmp_2(char *bloc_cleaned)
{
	if (!(ft_strcmp(bloc_cleaned, bloc_4_0)))
		bloc_cleaned = ".#\n.#\n##";
	if (!(ft_strcmp(bloc_cleaned, bloc_4_1)))
		bloc_cleaned = ".#\n.#\n##";
	if (!(ft_strcmp(bloc_cleaned, bloc_4_2)))
		bloc_cleaned = ".#\n.#\n##";
	if (!(ft_strcmp(bloc_cleaned, bloc_5_0)))
		bloc_cleaned = "###\n.#.";
	if (!(ft_strcmp(bloc_cleaned, bloc_5_1)))
		bloc_cleaned = "###\n.#.";
	if (!(ft_strcmp(bloc_cleaned, bloc_7_0)))
		bloc_cleaned = "###\n#";
	if (!(ft_strcmp(bloc_cleaned, bloc_7_1)))
		bloc_cleaned = "###\n#";
	if (!(ft_strcmp(bloc_cleaned, bloc_8_0)))
		bloc_cleaned = "###\n..#";
	if (!(ft_strcmp(bloc_cleaned, bloc_8_1)))
		bloc_cleaned = "###\n..#";
	if (!(ft_strcmp(bloc_cleaned, bloc_9_0)))
		bloc_cleaned = "##.\n.##";
	if (!(ft_strcmp(bloc_cleaned, bloc_9_1)))
		bloc_cleaned = "##.\n.##";
	return ((bloc_cleaned = start_cmp_3(bloc_cleaned)));
}

char	*start_cmp(char *bloc_cleaned)
{
	if (!(ft_strcmp(bloc_cleaned, bloc_1_0)))
		bloc_cleaned = "##\n##\0";
	if (!(ft_strcmp(bloc_cleaned, bloc_1_1)))
		bloc_cleaned = "##\n##\0";
	if (!(ft_strcmp(bloc_cleaned, bloc_1_2)))
		bloc_cleaned = "##\n##\0";
	if (!(ft_strcmp(bloc_cleaned, bloc_2_0)))
		bloc_cleaned = "#\n#\n#\n#\0";
	if (!(ft_strcmp(bloc_cleaned, bloc_2_1)))
		bloc_cleaned = "#\n#\n#\n#\0";
	if (!(ft_strcmp(bloc_cleaned, bloc_2_2)))
		bloc_cleaned = "#\n#\n#\n#\0";
	if (!(ft_strcmp(bloc_cleaned, bloc_2_3)))
		bloc_cleaned = "#\n#\n#\n#\0";
	if (!(ft_strcmp(bloc_cleaned, bloc_3_0)))
		bloc_cleaned = "#.\n#.\n##";
	if (!(ft_strcmp(bloc_cleaned, bloc_3_1)))
		bloc_cleaned = "#.\n#.\n##";
	if (!(ft_strcmp(bloc_cleaned, bloc_3_2)))
		bloc_cleaned = "#.\n#.\n##";
	bloc_cleaned = start_cmp_2(bloc_cleaned);
	return (bloc_cleaned);
}

char	*tetrixcmp(char *bloc, size_t sharp_nbr, size_t i)
{
	char	*tmp;
	char	*tmp_2;
	size_t	size;

	size = 0;
	tmp = ft_strchr(bloc, '#');
	if (!(tmp_2 = ft_strnew(ft_strlen(tmp))))
		return (NULL);
	while (tmp[i] && sharp_nbr < 4)
	{
		if (tmp[i] == '#')
			sharp_nbr++;
		tmp_2[i] = tmp[i];
		i++;
	}
	tmp_2 = start_cmp(tmp_2);
	return (tmp_2);
}
