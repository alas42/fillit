/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:47:28 by ralleman          #+#    #+#             */
/*   Updated: 2019/02/01 18:50:14 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_block(char ***board, int n, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if ((*(board))[i][j] == n + 65)
				(*(board))[i][j] = '.';
	}
}

char	**resolve(char ***board, int n, int size)
{
	static int	res = 0;
	int			i;
	int			j;

	i = -1;
	while (++i < size && res == 0)
	{
		j = -1;
		while (++j < size && res == 0)
		{
			if (block_fit(*board, n, j, i) == 1)
			{
				put_in_board(board, n);
				if (n + 1 == struct_len())
					res = 1;
				else
					resolve(board, n + 1, size);
			}
		}
	}
	if (res == 0)
		delete_block(board, n - 1, size);
	if (res == 0 && n == 0)
		return (NULL);
	return (*board);
}
