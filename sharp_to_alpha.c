/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp_to_alpha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:03:11 by ralleman          #+#    #+#             */
/*   Updated: 2018/12/19 14:12:33 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	sharp_to_alpha(int nblock)
{
	int i;
	int j;
	int k;

	i = -1;
	while (++i < nblock)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (t_block[i].line[j][++k] != '\0')
				if (t_block[i].line[j][k] == '#')
					t_block[i].line[j][k] = i + 65;
		}
	}
}
