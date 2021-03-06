/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:32:09 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/06 02:17:44 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		res;
	char	*buffer;

	fd = 0;
	res = 0;
	buffer = malloc(sizeof(char*) * READ_BUFFER + 1);
	if (argc != 2)
		ft_putstr("error\n");
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			ft_putstr("error\n");
		else
		{
			res = read(fd, buffer, READ_BUFFER);
			buffer[READ_BUFFER + 1] = '\0';
			if (check_all(buffer))
				fd = 666;
			else
				ft_putstr("error\n");
			free(buffer);
		}
	}
}
