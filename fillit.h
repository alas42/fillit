/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:14:51 by ralleman          #+#    #+#             */
/*   Updated: 2019/02/18 16:06:26 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

struct		s_block
{
	int		heigth;
	int		width;
	char	line[5][5];
	int		x;
	int		y;
}			t_block[26];

int			get_blocks(char *file, int i, int k);
int			check_error(char *str, char *file);
char		*get_one_line(char *file);
void		sharp_to_alpha(int nblock);
void		show_g_tetri(void);
int			check_blocks(int nblock);
int			allocate_board(char ***board, int size);
void		fill_struc(int nblock);
int			get_board_size(int nb_block);
int			block_fit(char **board, int n, int x, int y);
void		print_board(char **board);
void		put_in_board(char ***board, int n);
char		**resolve(char ***board, int n, int size);
int			struct_len(void);
int			resize_board(char ***board, int size);
void		free_board(char **board);

#endif
