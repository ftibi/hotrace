/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 05:41:26 by justasze          #+#    #+#             */
/*   Updated: 2016/04/23 11:21:20 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		p;

	p = 0;
	while ((s1[p]) && (s1[p] == s2[p]))
		p++;
	return ((unsigned char)s1[p] - (unsigned char)s2[p]);
}
