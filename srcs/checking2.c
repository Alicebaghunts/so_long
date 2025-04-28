/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:41:43 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/24 19:44:00 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	// if (checking_valid_way_to_exit(map) == 0)
	// 	error_handling_map(map, fd);
	// if (checking_valid_way_to_coin(map) == 0)
	// 	error_handling_map(map, fd);
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

