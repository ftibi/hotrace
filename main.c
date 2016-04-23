/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 11:17:30 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/23 11:50:22 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	main(void)
{
	char	*key;
	char	*value;
	char	*tmp;
	int		read = 1;
	t_node	*root = 0;

	while (read)
	{
		read = get_next_line(0, &key);
		read = get_next_line(0, &value);
		if (!ft_strcmp(key, ""))
			read = 0;
		else
			root = add_node(root, key, value);
	}
	while (get_next_line(0, &tmp) > 0)
		search_key(root, key);
	destroy_tree(root);
		
	return (0);
}
