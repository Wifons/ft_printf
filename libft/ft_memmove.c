/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wifons <wifons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:34:14 by wifons            #+#    #+#             */
/*   Updated: 2025/01/13 18:05:28 by wifons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char				*dest_new;
	const unsigned char			*src_new;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		dest_new = (unsigned char *)dest;
		src_new = (const unsigned char *)src;
		while (n--)
			*dest_new++ = *src_new++;
	}
	else
	{
		dest_new = (unsigned char *)dest + (n - 1);
		src_new = (const unsigned char *)src + (n - 1);
		while (n--)
			*dest_new-- = *src_new--;
	}
	return (dest);
}
