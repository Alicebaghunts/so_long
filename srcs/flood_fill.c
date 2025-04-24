#include "so_long.h"
#include <stdlib.h>

const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void	flood_fill(char **map, int startX, int startY, int **visited, t_map *m)
{
	int	*queueX;
	int	*queueY;
	int	front;
	int	back;
	int	x;
	int	y;
	int	i;
	int	nx;
	int	ny;

	front = 0;
	back = 0;
	queueY = malloc(m->width * m->height * sizeof(int));
	queueX = malloc(m->width * m->height * sizeof(int));
	queueX[back] = startX;
	queueY[back] = startY;
	back++;
	while (front < back)
	{
		x = queueX[front];
		y = queueY[front];
		front++;
		if (visited[y][x])
			continue ;
		visited[y][x] = 1;
		i = 0;
		while (i < 4)
		{
			nx = x + directions[i][0];
			ny = y + directions[i][1];
			if (nx >= 0 && ny >= 0 && nx < m->width && ny < m->height)
			{
				if (!visited[ny][nx] && (map[ny][nx] == '0'
					|| map[ny][nx] == 'P' || map[ny][nx] == 'C'
					|| map[ny][nx] == 'E'))
				{
					queueX[back] = nx;
					queueY[back] = ny;
					back++;
				}
			}
			i++;
		}
	}
	free(queueX);
	free(queueY);
}

int	check_valid_path_to_exit(t_map *map)
{
	int	**visited;
	int	playerX;
	int	playerY;
	int foundExit;
	int	x;
	int	y;

	playerX = -1;
	playerY = -1;
	foundExit = 0;
	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				playerX = x;
				playerY = y;
				break ;
			}
			x++;
		}
		if (playerX != -1)
			break ;
		y++;
	}
	if (playerX == -1 || playerY == -1)
		return (0);
	visited = malloc(map->height * sizeof(int *));
	y = 0;
	while (y < map->height)
	{
		visited[y] = malloc(map->width * sizeof(int));
		y++;
	}
	flood_fill(map->map, playerX, playerY, visited, map);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'E' && visited[y][x] == 1)
			{
				foundExit = 1;
				break ;
			}
			x++;
		}
		if (foundExit)
			break ;
		y++;
	}
	y = 0;
	while (y < map->height)
		free(visited[y++]);
	free(visited);
	return (foundExit);
}

int	check_valid_path_to_coins(t_map *map)
{
	int	**visited;
	int	playerX;
	int	playerY;
	int coinPaths;
	int	x;
	int	y;

	playerX = -1;
	playerY = -1;
	x = 0;
	y = 0;
	coinPaths = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				playerX = x;
				playerY = y;
				break ;
			}
			x++;
		}
		if (playerX != -1)
			break ;
		y++;
	}
	if (playerX == -1 || playerY == -1)
		return (0);
	visited = malloc(map->height * sizeof(int *));
	y = 0;
	while (y < map->height)
		visited[y++] = malloc(map->width * sizeof(int));
	flood_fill(map->map, playerX, playerY, visited, map);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'C' && visited[y][x] == 1)
			{
				coinPaths++;
				if (coinPaths >= 2)
				{
					y = 0;
					while (y < map->height)
					{
						free(visited[y]);
						y++;
					}
					free(visited);
					return (1);
				}
			}
			x++;
		}
		y++;
	}
	y = 0;
	while (y < map->height)
		free(visited[y++]);
	free(visited);
	return (0);
}

int	checking_valid_way_to_exit(t_map *map)
{
	return (check_valid_path_to_exit(map));
}

int	checking_valid_way_to_coin(t_map *map)
{
	return (check_valid_path_to_coins(map));
}
