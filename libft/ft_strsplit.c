/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:09:13 by ralleman          #+#    #+#             */
/*   Updated: 2018/11/15 15:33:46 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_len(char *s, int i, char c)
{
	int		k;

	k = 0;
	while (s[i] != c && s[i])
	{
		k++;
		i++;
	}
	return (k);
}

static int		ft_nbword(char const *s, char c)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			ret++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (ret);
}

static char		**ft_fill(char **str, const char *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i])
	{
		while ((s[i] == c) && s[i])
			i++;
		if (s[i])
		{
			k = 0;
			if (!(str[j] = (char*)malloc(sizeof(char)
							* ft_len((char *)s, i, c) + 1)))
				return (NULL);
			while (s[i] != c && s[i])
				str[j][k++] = s[i++];
			str[j++][k] = '\0';
		}
	}
	str[j] = NULL;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(char*) * (ft_nbword(s, c) + 1))))
		return (NULL);
	return (ft_fill(str, s, c));
}
