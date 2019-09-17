/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:41:36 by ralleman          #+#    #+#             */
/*   Updated: 2018/11/08 12:09:54 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	s1_end;
	size_t	lendst;

	lendst = ft_strlen(dst);
	i = 0;
	while (dst[i])
		i++;
	if (size < i)
		return (size + ft_strlen(src));
	s1_end = 0;
	while (src[s1_end] && i + s1_end < size - 1)
	{
		dst[i + s1_end] = src[s1_end];
		s1_end++;
	}
	dst[i + s1_end] = '\0';
	return (lendst + ft_strlen(src));
}
