/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wifons <wifons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:26:44 by wifons            #+#    #+#             */
/*   Updated: 2025/01/13 18:05:28 by wifons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_new;
	const unsigned char	*src_new;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	dest_new = (unsigned char *)dest;
	src_new = (const unsigned char *)src;
	i = 0;
	while (i++ < n)
		*dest_new++ = *src_new++;
	return (dest);
}
