/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrixcmp_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 03:12:21 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/15 03:13:40 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include "bloc.h"
#include "libft.h"

char	*start_cmp_5(char *bloc_cleaned)
{
	if (!(ft_strcmp(bloc_cleaned, bloc_27_0)))
		bloc_cleaned = "#\n##\n#";
	if (!(ft_strcmp(bloc_cleaned, bloc_28_0)))
		bloc_cleaned = "#\n##\n#";
	if (!(ft_strcmp(bloc_cleaned, bloc_29_0)))
		bloc_cleaned = "#\n###";
	if (!(ft_strcmp(bloc_cleaned, bloc_30_0)))
		bloc_cleaned = "..#\n###";
	return (bloc_cleaned);
}
