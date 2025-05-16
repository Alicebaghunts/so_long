/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-13 11:16:47 by alisharu          #+#    #+#             */
/*   Updated: 2025-05-13 11:16:47 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	if (flood_fill_for_e(map) == 0)
		error_handling_map(map, fd);
	if (flood_fill_for_c(map) == 0)
		error_handling_map(map, fd);
}

int	is_rectangular(t_map *matrix)
{
	int	i;
	int	len;

	if (!matrix || !matrix->map || !matrix->map[0])
		return (0);
	i = 0;
	len = ft_strlen(matrix->map[0]);
	while (matrix->map[i])
	{
		if (ft_strlen(matrix->map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	checking_argument(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

void	check_valid_images(t_game *data)
{
	if (!data->player->tank_up_1 || !data->player->tank_up_2
		|| !data->player->tank_down_1 || !data->player->tank_down_2
		|| !data->player->tank_left_1 || !data->player->tank_left_2
		|| !data->player->tank_right_1 || !data->player->tank_right_2
		|| !data->images->wall || !data->images->metal
		|| !data->images->gerb || !data->images->coin_bomb
		|| !data->images->coin_star || !data->images->background
	)
	{
		ft_putstr_fd("❌ \033[31mError: Invalid image\e[0m\n", 2);
		close_game(data);
	}
}
