/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:42:47 by ralleman          #+#    #+#             */
/*   Updated: 2018/11/10 15:03:44 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int i;
	unsigned int k;
	unsigned int save;

	i = 0;
	k = 0;
	save = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (needle[k] != '\0' && haystack[i] != '\0')
	{
		save = i;
		while ((needle[k] == haystack[i]) &&
			(needle[k] != '\0' && haystack[i] != '\0'))
		{
			if ((i - save) == ft_strlen(needle) - 1)
				return (&((char *)haystack)[save]);
			i++;
			k++;
		}
		i = save + 1;
		k = 0;
	}
	return (NULL);
}
