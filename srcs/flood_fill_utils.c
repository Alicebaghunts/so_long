/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-13 11:17:02 by alisharu          #+#    #+#             */
/*   Updated: 2025-05-13 11:17:02 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	position(t_map *map)
{
	t_game	data;

	data.x = 0;
	if (!map)
		return (data);
	while (data.x < map->height)
	{
		data.y = 0;
		while (data.y < map->width)
		{
			if (map->map[data.x][data.y] == 'P')
				return (data);
			data.y++;
		}
		data.x++;
	}
	return (data);
}

t_game	position_e(t_map *map, char **copy)
{
	t_game	data;

	data.x = 0;
	if (!map)
		return (data);
	while (data.x < map->height)
	{
		data.y = 0;
		while (data.y < map->width)
		{
			if (copy[data.x][data.y] == 'E')
				return (data);
			data.y++;
		}
		data.x++;
	}
	return (data);
}

void	dfs(char **map, t_map *s, int i, int j)
{
	if (i < 0 || j < 0 || i >= s->height || j >= s->width)
		return ;
	if (map[i][j] == '1' || map[i][j] == 'V' || map[i][j] == 'M'
		|| map[i][j] == 'B')
		return ;
	map[i][j] = 'V';
	dfs(map, s, i + 1, j);
	dfs(map, s, i - 1, j);
	dfs(map, s, i, j + 1);
	dfs(map, s, i, j - 1);
}

char	**copy_map(t_map *map)
{
	char	**res;
	int		i;
	int		j;

	res = malloc((map->height + 1) * sizeof(char *));
	i = 0;
	while (i < map->height)
	{
		j = 0;
		res[i] = malloc((map->width + 1) * sizeof(char));
		while (j < map->width)
		{
			res[i][j] = map->map[i][j];
			j++;
		}
		res[i][j] = 0;
		i++;
	}
	res[map->height] = 0;
	return (res);
}
