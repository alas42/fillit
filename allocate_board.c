/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_board.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:46:58 by ralleman          #+#    #+#             */
/*   Updated: 2019/02/18 15:50:59 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		init_board(char ***board, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			(*(board))[i][j++] = '.';
		(*(board))[i][j] = '\0';
		i++;
	}
}

int				allocate_board(char ***board, int size)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (!(*board = (char **)malloc(sizeof(char *) * (size + 1))))
	{
		ft_strdel(*board);
		return (-1);
	}
	while (i < size)
	{
		if (!((*(board))[i] = (char *)malloc(sizeof(char) * (size + 1))))
		{
			j = 0;
			while (*(board)[j] != NULL)
				ft_strdel(board[j++]);
			return (-1);
		}
		i++;
	}
	(*(board))[i] = 0;
	init_board(board, size);
	return (1);
}
