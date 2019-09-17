/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 10:54:38 by ralleman          #+#    #+#             */
/*   Updated: 2019/01/02 11:20:17 by ralleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*convert_base(unsigned int n, int base)
{
	static char representation[] = "0123456789ABCDEF";
	static char buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	while (n != 0)
	{
		*--ptr = representation[n % base];
		n /= base;
	}
	return (ptr);
}
