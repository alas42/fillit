/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:29:50 by ralleman          #+#    #+#             */
/*   Updated: 2018/11/15 15:30:26 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		first_space_count(char const *s)
{
	unsigned int	i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	return (i);
}

static unsigned int		scnd_space_count(char const *s)
{
	unsigned int	k;

	k = (ft_strlen(s) - 1);
	while ((s[k] == ' ' || s[k] == '\t' || s[k] == '\n') && k > 0)
		k--;
	return (k);
}

char					*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	unsigned int	k;
	unsigned int	j;

	if (s == NULL)
		return (0);
	if (*s == '\0')
		return ((char *)s);
	i = first_space_count(s);
	k = scnd_space_count(s);
	if (!(str = (char *)malloc(sizeof(char) * (k - i + 2))))
		return (NULL);
	j = 0;
	while (i <= k)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
