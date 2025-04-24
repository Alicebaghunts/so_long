/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:19:34 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/22 20:59:49 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "mlx.h"
#include "so_long.h"

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
	close(fd);
	ft_free_matrix(map->map);
	free(map);
	error_handling(INVALID_MAP);
}

void	checking(t_map *map, int fd)
{
	if (is_rectangular(map) == 0)
		error_handling_map(map, fd);
	if (checking_walls(map) == 0)
		error_handling_map(map, fd);
	if (checking_exits(map) == 0)
		error_handling_map(map, fd);
	if (checking_coins(map) == 0)
		error_handling_map(map, fd);
	if (checking_position(map) == 0)
		error_handling_map(map, fd);
	if (checking_all_characters(map) == 0)
		error_handling_map(map, fd);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	int		fd;
	char	**map_array;

	if (argc != 2)
		error_handling(INVALID_ARGUMENT);
	fd = check_and_open_map_file(argv[1]);
	map_array = read_in_map_file(fd);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		error_handling(MALLOC_ERROR);
	map->map = map_array;
	printf("map_array\n\n");
	print_matrix(map->map);
	init_map_first(map, find_width(map), find_height(map));
	printf("width -> %d\nheight - > %d\n", find_width(map), find_height(map));
	checking(map, fd);
	render_map(map);

	close(fd);
	ft_free_matrix(map->map);
	free(map);
	return (0);
}
