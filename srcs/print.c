/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:11:43 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/23 18:55:55 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix == NULL)
	{
		printf("Matrix is NULL\n");
		return ;
	}
	while (matrix[i] != NULL)
	{
		printf("%s\n", matrix[i]);
		i++;
	}
}
