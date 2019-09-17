/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_one_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:11:11 by ralleman          #+#    #+#             */
/*   Updated: 2018/12/20 13:30:11 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_feedline(char *buf, int ret)
{
	int		i;
	int		lf;

	i = 0;
	lf = 0;
	while (i < ret)
	{
		if (buf[i] == '\n')
			lf++;
		if ((lf % 5) == 0 && buf[i + 1] == '\n' && (i + 1) != ret && lf != 0
		&& buf[i] == '\n')
			return (-1);
		i++;
	}
	if (buf[i - 1] == '\n' && buf[i - 2] == '\n')
		return (-1);
	return (1);
}

char	*get_one_line(char *file)
{
	int		ret;
	int		fd;
	char	buf[550];
	char	*str;

	str = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	ret = read(fd, buf, 550);
	if (!(str = malloc(sizeof(char) * (ret + 1))))
		return (NULL);
	if (ret)
	{
		if (check_feedline(buf, ret) == -1)
			return (str = NULL);
		ft_strncpy(str, buf, ret);
		str[ret] = '\0';
	}
	close(fd);
	return (str);
}
