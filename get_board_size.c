/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:33:23 by ralleman          #+#    #+#             */
/*   Updated: 2018/12/19 14:00:00 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_board_size(int nb_blocks)
{
	int board_size;

	board_size = 2;
	while (board_size * board_size < nb_blocks * 4)
		board_size++;
	return (board_size);
}
