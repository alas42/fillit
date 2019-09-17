/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_blocks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:46:40 by ralleman          #+#    #+#             */
/*   Updated: 2018/12/20 15:34:14 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			get_blocks(char *file, int i, int k)
{
	int		ret;
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (ft_strlen(line) != 4 && (i + 1) < 4)
			return (-1);
		if (++i < 4)
			ft_strncpy(t_block[k].line[i], line, 4);
		else
		{
			t_block[k].line[i][0] = '\0';
			i = -1;
			k++;
		}
		ft_strdel(&line);
	}
	close(fd);
	if (ret == -1)
		return (-1);
	return (0);
}
