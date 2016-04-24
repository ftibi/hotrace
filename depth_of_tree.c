/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_of_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 20:46:48 by tbeauman          #+#    #+#             */
/*   Updated: 2016/04/24 16:56:34 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

size_t		max(size_t a, size_t b)
{
	return (a > b ? a : b);
}

size_t		depth(t_node *root)
{
	if (!root)
		return (0);
	return (root->depth);
}
