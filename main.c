/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:05:49 by ralleman          #+#    #+#             */
/*   Updated: 2019/02/18 15:51:58 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		n_block;
	char	**board;
	int		size;

	board = NULL;
	if (ac != 2 || check_error(get_one_line(av[1]), av[1]) == -1)
	{
		ac != 2 ? ft_putendl("usage : ./fillit target_file")
			: ft_putendl("error");
		return (0);
	}
	n_block = check_error(get_one_line(av[1]), av[1]);
	fill_struc(n_block);
	size = get_board_size(n_block);
	if (allocate_board(&board, size) == -1)
		return (0);
	while (resolve(&board, 0, size) == NULL)
		if (resize_board(&board, ++size) == -1)
			return (0);
	print_board(board);
	free_board(board);
	return (0);
}
