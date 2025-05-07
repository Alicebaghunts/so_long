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

t_game	position(t_map *map)
{
	t_game	ij;

	ij.x = 0;
	if (!map)
		return (ij);
	while (ij.x < map->height)
	{
		ij.y = 0;
		while (ij.y < map->width)
		{
			if (map->map[ij.x][ij.y] == 'P')
				return (ij);
			ij.y++;
		}
		ij.x++;
	}
	return (ij);
}

t_game	position_e(t_map *map, char **copy)
{
	t_game	ij;

	ij.x = 0;
	if (!map)
		return (ij);
	while (ij.x < map->height)
	{
		ij.y = 0;
		while (ij.y < map->width)
		{
			if (copy[ij.x][ij.y] == 'E')
				return (ij);
			ij.y++;
		}
		ij.x++;
	}
	return (ij);
}

static void	dfs(char **map, t_map *s, int i, int j)
{
	if (i < 0 || j < 0 || i >= s->height || j >= s->width)
		return ;
	if (map[i][j] == '1' || map[i][j] == 'V')
		return ;
	map[i][j] = 'V';
	dfs(map, s, i + 1, j);
	dfs(map, s, i - 1, j);
	dfs(map, s, i, j + 1);
	dfs(map, s, i, j - 1);
}

static char	**copy_map(t_map *map)
{
	char	**res;
	int		i;
	int		j;

	res = malloc(map->height * sizeof(char));
	i = 0;
	printf("%d %d\n", map->height, map->width);
	while (i < map->height)
	{
		j = 0;
		printf("aa\n");
		res[i] = malloc(map->width * sizeof(char));
		while (j < map->width)
		{
			res[i][j] = map->map[i][j];
			j++;
		}
		i++;
	}
	return (res);
}

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
	int i;
	int j;
	char **copy;

	copy = copy_map(map);
	i = position(map).x;
	j = position(map).y;
	printf("qq\n");
	copy[position_e(map, copy).x][position_e(map, copy).y] = '1';
	dfs(copy, map, i, j);
	i = 1;
	while (i < map->height)
	{
		j = 1;
		while (j < map->width)
		{
			if (copy[i][j] == 'C')
			{
				printf("qq\n");
				ft_free_matrix(copy);
				return (0);
			}
			j++;
		}
		i++;
	}
	printf("qq\n");
	ft_free_matrix(copy);
	return (1);
}