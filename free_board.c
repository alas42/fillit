/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:42:49 by ralleman          #+#    #+#             */
/*   Updated: 2019/02/18 15:33:18 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_board(char **board)
{
	int i;
	int size;

	size = (int)ft_strlen(board[0]);
	i = 0;
	while (i < size)
	{
		ft_strdel(&(board[i]));
		i++;
	}
	free(board);
	board = NULL;
}
