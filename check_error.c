/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:14:27 by ralleman          #+#    #+#             */
/*   Updated: 2019/01/11 16:21:42 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_error(char *str, char *file)
{
	int len;
	int sharp;
	int dot;

	if (str == NULL)
		return (-1);
	len = ft_strlen(str);
	sharp = 0;
	dot = 0;
	while (--len >= 0)
	{
		if (!(str[len] == '#' || str[len] == '.' || str[len] == '\n'))
			return (-1);
		if (str[len] == '#')
			sharp++;
		if (str[len] == '.')
			dot++;
	}
	if ((((sharp + dot) % 16) != 0) || (sharp % 4) != 0 || sharp == 0)
		return (-1);
	if ((sharp / 4) > 26 || get_blocks(file, -1, 0) == -1
		|| check_blocks(sharp / 4) == -1)
		return (-1);
	ft_strdel(&str);
	return (sharp / 4);
}
