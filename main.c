/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 11:17:30 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/23 15:15:06 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	main(void)
{
	char	*key;
	char	*value;
	char	*tmp;
	int		read;
	t_node	*root;

	read = 1;
	root = 0;
	while (read)
	{
		read = get_next_line(0, &key);
		read = get_next_line(0, &value);
		if (!ft_strcmp(key, ""))
			read = 0;
		else
		{
			if (!root)
				root = add_node(root, key, value);
			else
			{
				add_node(root, key, value);
				//root = balance_tree(root); //a implementer pour equilibrer l'arbre
			}
		}
	}
	search_key(root, value);
	while (get_next_line(0, &tmp) > 0)
		search_key(root, tmp);
	destroy_tree(root);
	sleep(3600);
	return (0);
}
