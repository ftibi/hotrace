/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:37:13 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/24 16:43:35 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*str;
	size_t			i;

	if (size == 0)
		return (NULL);
	str = (unsigned char*)malloc(size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return ((void*)str);
}
