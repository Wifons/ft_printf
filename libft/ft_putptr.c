/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wifons <wifons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:18:57 by wifons            #+#    #+#             */
/*   Updated: 2025/01/14 20:30:09 by wifons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putptr(void *ptr)
{
	char	*str;
	ssize_t	len;

	if (ft_putstr("0x") == -1)
		return (-1);
	if (ptr == 0)
		return (ft_putstr("0"));
	str = ft_itoa_base((unsigned long)ptr, "0123456789abcdef");
	if (!str)
		return (-1);
	len = ft_putstr(str);
	free(str);
	return (len + 2);
}
