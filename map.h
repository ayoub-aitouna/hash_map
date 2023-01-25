/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <aaitouna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:14:54 by aaitouna          #+#    #+#             */
/*   Updated: 2023/01/25 00:57:29 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "./linked_list/linked_list.h"
# define HASH_MAP_DEFAULT_SIZE 16

typedef struct s_list
{
	char *key;
	void *value;
	u_int32_t hash;
	struct s_list *next;
} t_list;

typedef struct hash_map{
	struct s_list **arr;
	size_t size;
} t_hash_map;

int get_index_by_hash(u_int32_t hash_code, int size);
int hash(char *s);
t_list	*ft_lstnew(char *key, void *value, u_int16_t hash);
void ft_lstadd_front(t_list **lst, t_list *new);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(t_list *));
t_list *ft_lstmap(t_list *lst, void *(*f)(t_list *),
				  void (*del)(t_list *));	
#endif