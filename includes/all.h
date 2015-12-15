/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:25:55 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/06 02:16:33 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# define READ_BUFFER 572

int				check_all(char *buf);
typedef struct	s_trix
{
	short			**form;
	short			**old_form;
	short			*size;
	short			*old_size;
	short			boolean;
	short			nbr;
	short			size_tab;
	char			*all_char;
	char 			*tetrix_char;
	struct s_trix	*next;
}				t_trix;
t_trix			*do_struct(char *buf, size_t start);
void			ft_lstaddendtrix(t_trix **list, t_trix *toadd);
int				getdif(int a, int b);
int				check_position_2(size_t i, size_t lines, int end, int sharp);
char			*tetrixcmp(char *bloc, size_t sharp_nbr, size_t i);
char			*start_cmp_5(char *bloc_cleaned);
void			do_struct_bytes(t_trix *bloc, size_t bloc_nbr, size_t i, size_t lines);
			//////////////////
			//	  SYSTEM 	//
			//////////////////
t_trix				*resolver_of_trix(t_trix *all_trix);
t_trix				*resolver_of_Resolution(t_trix *all_trix, short id,  short fixed);
t_trix				*deplace_form(t_trix *all_trix, short id, short index);

			//////////////////
			//	 FORMULAS 	//
			//////////////////
short				size_tab(short size_byte_tab);
t_trix				*reset_all_form(t_trix *trix);

			//////////////////
			//	 FINDING	//
			//////////////////
short				possible_fixed(t_trix *all_trix, short id, short dir);
void				move_down_bloc(t_trix *all_trix, short id);
void				right(t_trix *all_trix, short id);

			//////////////////
			//	  OUTPUT  	//
			//////////////////
void				put_trix(short *lines, short size, short nbr_line);
short				*all_line(t_trix *all_bloc, short line_cible);
short				nbr_all_line(t_trix *all_bloc, short line_cible);
void				put_tab(t_trix *final);
#endif
