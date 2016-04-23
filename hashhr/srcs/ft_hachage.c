/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hachage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillot <tguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 11:46:55 by tguillot          #+#    #+#             */
/*   Updated: 2016/04/24 00:21:29 by tguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

int	ft_hachage(char *line)
{
	int a;
	int nbrhache;

	a = 0;
	nbrhache = 0;
	while (line[a] != '\0')
	{
		nbrhache += line[a] * (a + 1);
		a++;
	}
	nbrhache %= TAB_SIZE;
	return (nbrhache);
}
