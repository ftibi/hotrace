/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 00:44:20 by tguillot          #+#    #+#             */
/*   Updated: 2016/04/24 16:28:28 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# define BUFF_SIZE 10
# define FD_SIZE 2147483647
# define TAB_SIZE 1000

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_data
{
	char			*key;
	char			*data;
	struct s_data	*next;
}					t_data;

typedef struct		s_node
{
	char			*key;
	char			*value;
	int				depth;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

int					get_next_line(int const fd, char **line);
void				ft_putchar(char c);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);
void	ft_strdel(char **as);
void	ft_memdel(void **ap);
int					ft_hachage(char *line);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strlen(const char *s);
void				ft_bzero(void *s, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strnew(size_t size);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_tab_init(t_node **tab);
void				ft_tab_destroy(t_node **tab);
void				ft_stock_data(t_node **tab, char *value, char *key);
void				ft_print_data(t_node **tab);
void				ft_putnbr(int n);
void				ft_putnbrdl(int n);
int					ft_iterative_power(int nb, int power);
void				ft_search(t_node **tab);

t_node				*new_node(char *key, char *value);
void				add_node(t_node **root, char *key, char *value);
char				*search_key(t_node *root, char *key);
int					destroy_tree(t_node **root);
int					destroy_node(t_node **node);
t_node *rotate_tree_right(t_node *y);
t_node *rotate_tree_left(t_node *x);
size_t	max(size_t a, size_t b);
size_t		depth(t_node *root);


#endif
