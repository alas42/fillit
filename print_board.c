/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:34:17 by avogt             #+#    #+#             */
/*   Updated: 2018/12/19 14:10:43 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_board(char **board)
{
	int i;

	i = 0;
	if (board == NULL)
		return ;
	while (board[i] != NULL)
		ft_putendl(board[i++]);
}
