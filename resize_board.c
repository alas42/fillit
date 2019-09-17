/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:25:07 by avogt             #+#    #+#             */
/*   Updated: 2019/02/18 15:33:33 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		resize_board(char ***board, int size)
{
	int i;

	i = 0;
	while (i < size)
		free((*(board))[i++]);
	free(*board);
	if (allocate_board(board, size) == -1)
		return (-1);
	return (1);
}

char	**empty_board(char ***board, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
		j = -1;
	while (++j < size)
		(*(board))[i][j] = '.';
	return (*board);
}
