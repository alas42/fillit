/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:35:14 by ralleman          #+#    #+#             */
/*   Updated: 2019/01/11 16:23:31 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		find_height(int n)
{
	int height;
	int counter;
	int j;
	int i;

	i = 0;
	height = 0;
	counter = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (t_block[n].line[i][j] == '#')
				counter++;
			if (t_block[n].line[i][j] == '#' && counter == 1)
				height = 0;
			else if (t_block[n].line[i][j] == '#' && counter == 4)
				height = i - height;
			j++;
		}
		i++;
	}
	return (height + 1);
}

static int		find_width(int n)
{
	int width;
	int j;
	int i;

	i = 0;
	width = 0;
	while (i < 4)
	{
		j = 0;
		while (t_block[n].line[i][j] != '\0')
		{
			if (t_block[n].line[i][j] == '#')
			{
				if (i == 0)
					width++;
				else if (i > 0 && t_block[n].line[i - 1][j] != '#')
					width++;
			}
			j++;
		}
		i++;
	}
	return (width);
}

static void		move_col(int nblock, int n)
{
	int i;
	int j;

	while (++n < nblock)
	{
		while (t_block[n].line[0][0] == '.' && t_block[n].line[1][0] == '.'
				&& t_block[n].line[2][0] == '.' && t_block[n].line[3][0] == '.')
		{
			i = -1;
			while (++i < 4)
			{
				j = -1;
				while (++j < 3)
					if (t_block[n].line[i][j + 1] == '.')
						t_block[n].line[i][j] = '.';
					else
					{
						t_block[n].line[i][j] = '#';
						t_block[n].line[i][j + 1] = '.';
					}
			}
		}
	}
}

static void		move_line(int nblock, int n)
{
	int i;
	int j;

	while (++n < nblock)
	{
		while (ft_strcmp(t_block[n].line[0], "....") == 0)
		{
			i = -1;
			while (++i < 3)
			{
				j = -1;
				while (++j < 4)
					if (t_block[n].line[i + 1][j] == '.')
						t_block[n].line[i][j] = '.';
					else
					{
						t_block[n].line[i][j] = '#';
						t_block[n].line[i + 1][j] = '.';
					}
			}
		}
	}
}

void			fill_struc(int nblock)
{
	int n;

	move_col(nblock, -1);
	move_line(nblock, -1);
	n = -1;
	while (++n < nblock)
	{
		t_block[n].heigth = find_height(n);
		t_block[n].width = find_width(n);
	}
	sharp_to_alpha(nblock);
}
