/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <aaitouna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:22:28 by aaitouna          #+#    #+#             */
/*   Updated: 2023/01/25 01:41:44 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./map.h"

t_hash_map *new_map()
{
	int			i;
	t_hash_map	*map;
	
	i = 0;
	map = malloc(sizeof(t_hash_map));
	map->arr = malloc(sizeof(t_list) * HASH_MAP_DEFAULT_SIZE);
	map->size = HASH_MAP_DEFAULT_SIZE;
	while (i < map->size)
		(map->arr[i++]) = NULL;
	return (map);
}

void map_put(t_hash_map *map, char *key, void *value)
{
	u_int16_t hash_code;
	t_list **head;
	t_list *node;
	int index;

	hash_code= hash(key);
	index = get_index_by_hash(hash_code, map->size);
	head = &(map->arr[index]);
	if(!(*head))
	{
		(*head) = ft_lstnew(key, value, hash_code);
		return ;
	}
	while ((*head))
	{
		if((*head)->hash == hash_code)
		{
			(*head)->value = value;
			return;
		}
		(*head) = (*head)->next;
	}
	(*head)->next = ft_lstnew(key, value, hash_code);
}

void *get_value(t_hash_map *map, char* key)
{
	u_int16_t hash_code = hash(key);
	int index = get_index_by_hash(hash_code, map->size);
	t_list *temp = map->arr[index];
	while (temp)
	{
		if(temp->hash == hash_code)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

int main(int ac, char **av)
{
	if(ac < 3)
		return (1);
	t_hash_map *new_hash_map = new_map();
	map_put(new_hash_map, av[1], av[2]);
	printf("value is <<%s>>\n", ((char *)get_value(new_hash_map,av[1])));
	return (0);	
}