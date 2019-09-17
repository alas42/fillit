/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_blocks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:15:50 by avogt             #+#    #+#             */
/*   Updated: 2018/12/19 11:13:25 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_colision(int j, int i, int n)
{
	int n_connect;

	n_connect = 0;
	if (j > 0)
		if (t_block[n].line[i][j - 1] == '#')
			n_connect++;
	if (j < 3)
		if (t_block[n].line[i][j + 1] == '#')
			n_connect++;
	if (i > 0)
		if (t_block[n].line[i - 1][j] == '#')
			n_connect++;
	if (i < 3)
		if (t_block[n].line[i + 1][j] == '#')
			n_connect++;
	return (n_connect);
}

int			check_blocks(int nblock)
{
	int i;
	int j;
	int n;
	int result;

	n = -1;
	while (++n < nblock)
	{
		i = 0;
		result = 0;
		while (i < 4)
		{
			j = 0;
			while (t_block[n].line[i][j] != '\0')
			{
				if (t_block[n].line[i][j] == '#')
					result += check_colision(j, i, n);
				j++;
			}
			i++;
		}
		if (result != 6 && result != 8)
			return (-1);
	}
	return (result);
}
