/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <aaitouna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:41:54 by aaitouna          #+#    #+#             */
/*   Updated: 2023/01/25 00:28:45 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "map.h"

int hash(char *s)
{
	u_int32_t hash_code;
	
	hash_code = 0xD8FEA3AA;
	while (*s)
		hash_code = 31 * (hash_code ^ *s++);
	return (hash_code);
}


int get_index_by_hash(u_int32_t hash_code, int size)
{
	return  (hash_code & (size - 1));
}