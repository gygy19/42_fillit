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
void		ft_putstr(char *str);
int			check_all(char *buf);
size_t		ft_strlen(char *str);
char		*ft_strnew(size_t size);
#endif
