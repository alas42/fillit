/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:47:24 by ralleman          #+#    #+#             */
/*   Updated: 2018/11/10 15:00:36 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t counter;

	counter = 0;
	while (counter < len)
	{
		((char*)b)[counter] = ((unsigned char)c);
		counter++;
	}
	return (b);
}
