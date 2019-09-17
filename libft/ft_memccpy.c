/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:02:28 by ralleman          #+#    #+#             */
/*   Updated: 2018/11/10 14:49:43 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		(*(unsigned char*)dst) = (*(unsigned char*)src);
		if ((*(unsigned char*)src) == ((unsigned char)c))
			return (dst + 1);
		dst++;
		src++;
	}
	return (NULL);
}
