/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:21:51 by alisharu          #+#    #+#             */
/*   Updated: 2025/01/24 19:25:54 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*dest;
	const unsigned char		*sorce;
	size_t					i;

	i = 0;
	dest = dst;
	sorce = src;
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		dest[i] = sorce[i];
		i++;
	}
	return (dest);
}
