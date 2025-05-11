/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-07 16:47:50 by alisharu          #+#    #+#             */
/*   Updated: 2025-05-07 16:47:50 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	flood_fill_for_e(t_map *map)
{
	int		i;
	int		j;
	char	**copy;

	copy = copy_map(map);
	i = position(map).x;
	j = position(map).y;
	dfs(copy, map, i, j);
	i = 1;
	while (i < map->height)
	{
		j = 1;
		while (j < map->width)
		{
			if (copy[i][j] == 'E')
			{
				ft_free_matrix(copy);
				return (0);
			}
			j++;
		}
		i++;
	}
	ft_free_matrix(copy);
	return (1);
}

int	flood_fill_for_c(t_map *map)
{
	int		i;
	int		j;
	char	**copy;

	copy = copy_map(map);
	i = position(map).x;
	j = position(map).y;
	copy[position_e(map, copy).x][position_e(map, copy).y] = '1';
	dfs(copy, map, i, j);
	i = 0;
	while (++i < map->height)
	{
		j = 0;
		while (++j < map->width)
		{
			if (copy[i][j] == 'C')
				return (ft_free_matrix(copy), 0);
		}
	}
	return (ft_free_matrix(copy), 1);
}
