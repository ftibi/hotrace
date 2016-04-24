/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:31:21 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/23 16:20:25 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *parse1;
	unsigned char *parse2;

	parse1 = (unsigned char*)s1;
	parse2 = (unsigned char*)s2;
	while (*parse2 && *parse1 && *parse1 == *parse2)
	{
		parse1++;
		parse2++;
	}
	return (*parse1 - *parse2);
}