/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:55:29 by ralleman          #+#    #+#             */
/*   Updated: 2018/12/12 11:28:14 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*fresh;
	unsigned int	tt_len;
	unsigned int	i;

	tt_len = (s1 == NULL) ? 1 : ft_strlen(s1) + 1;
	tt_len = (s2 == NULL) ? tt_len : tt_len + ft_strlen(s2);
	if (!(fresh = (char*)malloc(sizeof(char) * tt_len)))
		return (NULL);
	i = 0;
	while (i < tt_len - 1)
	{
		if (s1 != NULL)
			while (*s1 != '\0')
				fresh[i++] = *(s1++);
		if (s2 != NULL)
			while (*s2 != '\0')
				fresh[i++] = *(s2++);
	}
	fresh[i] = '\0';
	return (fresh);
}
