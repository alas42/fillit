/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:31:33 by avogt             #+#    #+#             */
/*   Updated: 2018/12/18 19:26:21 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_in_board(char ***board, int n)
{
	int x;
	int y;
	int i;
	int j;

	x = t_block[n].x;
	y = t_block[n].y;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (t_block[n].line[i][j] != '.')
				(*(board))[y + i][x + j] = t_block[n].line[i][j];
			j++;
		}
		i++;
	}
}
