/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:27:12 by ralleman          #+#    #+#             */
/*   Updated: 2018/11/10 14:55:52 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t counter;

	counter = 0;
	while (counter < n)
	{
		((char*)dst)[counter] = ((char*)src)[counter];
		counter++;
	}
	return (dst);
}
