/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 05:01:27 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/15 03:58:22 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include "libft.h"


t_trix		*deplace_form(t_trix *all_trix, short id, short index)
{
	short move_type;
	////////////////////////////////////////
	//		if index == 0 no move		  //
	////////////////////////////////////////
	if (index == 0)
	{
		if (possible_fixed(all_trix, id, 0))
		{
			all_trix->boolean = 1;
			return (all_trix);
		}		
	}
	////////////////////////////////////////
	//		verif right else go down	  //
	////////////////////////////////////////
	//		grace a cette fonction ont diverer les choix de direction pour le moment deplace de 2;
	move_type = possible_fixed(all_trix, id, 2);
	if (move_type == 1)
	{
		right(all_trix, id);
	}
	else if (move_type == 3)
	{
		move_down_bloc(all_trix, id);
		move_type = possible_fixed(all_trix, id, 0);
	}
	else
		right(all_trix, id);
	////////////////////////////////////////////////////////////
	//			look allbloc if good return all_trix		  //
	//					else return NULL					  //
	////////////////////////////////////////////////////////////
	ft_putstr("move_type : ");
	ft_putnbr(move_type);
	ft_putstr("\n");
	if (move_type == 1)
		all_trix->boolean = 1;
	return (all_trix);
}

t_trix		*resolver_of_Resolution(t_trix *all_trix, short id, short fixed)
{
	short x;
	t_trix *tmp;
	x = 0;
	if (fixed >= all_trix->nbr)
		return (all_trix);
	//	if (id > (fixed + 1))
	//	return (NULL);
	while (x < (((size_tab(all_trix->size_tab) * size_tab(all_trix->size_tab))
				- ((all_trix->size[id] - 1) * size_tab(all_trix->size_tab)))))
	{
		if ((tmp = deplace_form(all_trix, id, x)))
		{
			if (tmp->boolean)
			{
				tmp->boolean = 0;
				return (resolver_of_Resolution(tmp, id + 1, fixed + 1));
			}
		}
		else
			return (NULL);
		x++;
	}
	return (NULL);
}

t_trix		*resolver_of_trix(t_trix *all_trix)
{
	t_trix	*tmp;

	tmp = resolver_of_Resolution(all_trix, 0, 0);
	if (tmp != NULL)
		return (all_trix);

		///////////////////////
		//	  reset place    //
		///////////////////////
	all_trix = reset_all_form(all_trix);

		///////////////////////
		//      size++;      //
		///////////////////////
	all_trix->size_tab = all_trix->size_tab / 2;
	ft_putstr("size_tab : ");
	ft_putnbr (all_trix->size_tab);
	ft_putstr("\n");
	if (all_trix->size_tab == 1)
		return (all_trix);

		///////////////////////
		//  continue resolve //
		///////////////////////
	return (resolver_of_trix(all_trix));
}
