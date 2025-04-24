/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:50:30 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/24 19:43:53 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <stdio.h>

int	find_height(t_map *map)
{
	int	height;

	height = 0;
	if (map == NULL || map->map == NULL)
		return (0);
	while (map->map[height] != NULL)
		height++;
	return (height);
}

int	find_width(t_map *map)
{
	if (map == NULL || map->map == NULL || map->map[0] == NULL)
		return (0);
	return (ft_strlen(map->map[0]));
}

void	ft_free_matrix(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
