/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:52:09 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/26 16:26:54 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int	close_game(t_game *data)
{
	free_all_data(data);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_game *data)
{
	if (keycode == ESC)
		close_game(data);
	call_move(keycode, data);
	return (0);
}
void	move_up(t_game *data)
{
	int count;

	count = 1;
	data->player->y -= 16;
	while (data->player->y % TILE_SIZE != 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->images->background, data->player->x, data->player->y + 16);
		if (count % 2 == 1)
			mlx_put_image_to_window(data->mlx, data->win, data->player->tank_2, data->player->x, data->player->y);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->player->tank_1, data->player->x, data->player->y);
		count++;
		data->player->y -= 16;
		printf("x:%d y:%d\n", (data->player->y) / 64, (data->player->x) / 64);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->images->background, data->player->x, data->player->y + 16);
	mlx_put_image_to_window(data->mlx, data->win, data->player->tank_1, data->player->x, data->player->y);
}

void	call_move(int keycode, t_game *data)
{
	printf("keykode: %d\n", keycode);
	if (data->player->y % 64 != 0 && data->player->y % 64 != 0)
		return ;
	if ((keycode == UP)
		&& data->map->map[(data->player->y - 16) / 64][(data->player->x) / 64] != '1')
	{
		printf("before: %d\n", data->player->y / 64);
		move_up(data);
		printf("after: %d\n", data->player->y / 64);
		//data->player->y -= 16;
	}
	// else if ((keycode == DOWN)
	// 	&& data->map->map[(data->player->y + 16) / 64][(data->player->x) / 64] != '1')
	// {
	// 	move_down(data);
	// 	//data->player->y += 16;
	// }
	// else if ((keycode == LEFT)
	// 	&& data->map->map[(data->player->y) / 64][(data->player->x - 16) / 64] != '1')
	// {
	// 	move_left(data);
	// 	//data->player->x -=16;
	// }
	// else if ((keycode == RIGHT)
	// 	&& data->map->map[(data->player->y) / 64][(data->player->x + 16) / 64] != '1')
	// {
	// 	move_right(data);
	// 	//data->player->x +=16;
	// }
}

void	render_map(t_map *map)
{
	t_game	*data;

	data = malloc(sizeof(t_game));
	if (!data)
		error_handling(MALLOC_ERROR);
	data->map = map;

	data->images = malloc_img(data->map);
	data->enemy = malloc_enemy(data->map, data->images);
	data->player = malloc_tank(data->map, data->images, data->enemy);

	data->mlx = mlx_init();
	if (!data->mlx)
	{
		perror("Failed to initialize mlx");
		free_all_characters(data);
		free_all_data(data);
		error_handling(MALLOC_ERROR);
	}

	data->win = mlx_new_window(data->mlx, map->width * 64, map->height * 64, "so_long");
	if (!data->win)
	{
		perror("Failed to create window");
		free_all_characters(data);
		free_all_data(data);
		error_handling(MALLOC_ERROR);
	}

	//put_position(data->enemy);
	put_images(data);
	find_player_position(data);
	mlx_hook(data->win, 17, 0, close_game, data);
	mlx_key_hook(data->win, &key_hook, data);
	mlx_loop(data->mlx);
}


char	**resize_map(char **map, int *map_size)
{
	char	**new_map;
	int		i;

	*map_size *= 2;
	new_map = (char **)malloc(sizeof(char *) * (*map_size));
	if (!new_map)
		error_handling(MALLOC_ERROR);
	i = 0;
	while (i < *map_size / 2)
	{
		new_map[i] = map[i];
		i++;
	}
	free(map);
	return (new_map);
}

char	**read_in_map_file(int fd)
{
	char	**map;
	char	*line;
	char	*pxik;
	int		height;
	int		map_size;

	map = malloc(sizeof(char *) * 10);
	if (!map)
		error_handling(MALLOC_ERROR);
	map_size = 10;
	height = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		pxik = ft_strtrim(line, "\n");
		free(line);
		if (!pxik)
			error_handling(MALLOC_ERROR);
		if (height >= map_size)
			map = resize_map(map, &map_size);
		map[height++] = pxik;
	}
	if (height == 0)
	{
		free(map);
		error_handling(INVALID_MAP);
	}
	map[height] = NULL;
	return (map);
}
