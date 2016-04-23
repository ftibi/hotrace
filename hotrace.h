/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 11:10:41 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/23 12:08:53 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "libft/includes/libft.h"

typedef struct		s_node
{
	struct s_node	*parent;
	struct s_node	*left;
	struct s_node	*right;
	char			color;
	char			*key;
	char			*value;
}					t_node;

t_node				*new_node(t_node *parent, char *key, char *value);
t_node				*add_node(t_node *root, char *key, char *value);
void				search_key(t_node *root, char *key);
void				destroy_tree(t_node *root);
void				destroy_node(t_node *node);

#endif
