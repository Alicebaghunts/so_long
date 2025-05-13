/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-13 11:18:28 by alisharu          #+#    #+#             */
/*   Updated: 2025-05-13 11:18:28 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_handling(int num)
{
	if (num == 1)
		ft_putstr_fd("❌ \033[31mError: Invalid argument\e[0m\n", 2);
	else if (num == 2)
		ft_putstr_fd("❌ \033[31mError: Invalid path\e[0m\n", 2);
	else if (num == 3)
		ft_putstr_fd("❌ \033[31mError: Failed to open file\e[0m\n", 2);
	else if (num == 4)
		ft_putstr_fd("❌ \033[31mError: Invalid map\e[0m\n", 2);
	else if (num == 5)
		ft_putstr_fd("❌ \033[31mError: Failed to malloc\e[0m\n", 2);
	exit(num);
}

void	error_handling_map(t_map *map, int fd)
{
	(void)map;
	close(fd);
	ft_free_matrix(map->map);
	free(map);
	error_handling(INVALID_MAP);
}

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
