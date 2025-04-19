/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:58:17 by alisharu          #+#    #+#             */
/*   Updated: 2025/01/24 13:11:42 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str1;
	char	*str2;
	size_t	size;

	str1 = (char *)haystack;
	str2 = (char *)needle;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len > 0)
	{
		str1 = (char *)haystack;
		str2 = (char *)needle;
		size = len;
		while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2 && size != 0)
		{
			size--;
			str1++;
			str2++;
		}
		if (*str2 == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
