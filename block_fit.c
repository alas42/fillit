/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_fit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:43:53 by ralleman          #+#    #+#             */
/*   Updated: 2018/12/19 11:11:17 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		block_fit(char **board, int n, int x, int y)
{
	int i;
	int j;
	int size;

	size = (int)ft_strlen(board[0]);
	i = -1;
	if (y + t_block[n].heigth > size)
		return (-1);
	while (++i < t_block[n].heigth)
	{
		j = -1;
		while (++j < t_block[n].width)
		{
			if ((t_block[n].line[i][j] != '.' && board[y + i][x + j] != '.'))
				return (-1);
		}
	}
	t_block[n].x = x;
	t_block[n].y = y;
	return (1);
}
