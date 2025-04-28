/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:19:34 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/26 15:47:03 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (0);
}
