/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-19 14:52:14 by alisharu          #+#    #+#             */
/*   Updated: 2025-04-19 14:52:14 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_map_first(t_map *map, int width, int height)
{
	if (map == NULL)
		return ;
	map->coin = 0;
	map->exit = 0;
	map->height = height;
	map->width = width;
}

void	malloc_map(t_map *map)
{
	int	i;

	map->map = (char **)malloc(sizeof(char *) * map->height);
	if (map->map == NULL)
		error_handling(MALLOC_ERROR);
	i = 0;
	while (i < map->height)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (map->width + 1));
		if (map->map[i] == NULL)
		{
			free(map->map);
			error_handling(MALLOC_ERROR);
		}
		i++;
	}
}

int	check_and_open_map_file(char *path)
{
	char	**split;
	int		fd;

	if (checking_argument(path) == 0)
		error_handling(INVALID_PATH);
	split = ft_split(path, ' ');
	if (split == NULL)
		error_handling(INVALID_PATH);
	if (split[1] != NULL)
	{
		ft_free_matrix(split);
		error_handling(INVALID_PATH);
	}
	fd = open(split[0], O_RDONLY);
	ft_free_matrix(split);
	if (fd == -1)
		error_handling(INVALID_FILE);
	return (fd);
}
