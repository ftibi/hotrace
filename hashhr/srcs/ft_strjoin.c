/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillot <tguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 16:30:01 by tguillot          #+#    #+#             */
/*   Updated: 2016/04/23 11:36:31 by tguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		b;
	size_t		c;
	size_t		d;
	char		*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	b = ft_strlen(s2) + ft_strlen(s1);
	c = 0;
	d = 0;
	if (!(str = (char *)malloc(sizeof(char) * (b + 1))))
		return (NULL);
	while (s1[c])
	{
		str[c] = s1[c];
		c++;
	}
	while (c < b)
	{
		str[c] = s2[d];
		c++;
		d++;
	}
	str[b] = '\0';
	return (str);
}
