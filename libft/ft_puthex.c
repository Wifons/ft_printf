/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wifons <wifons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:19:47 by wifons            #+#    #+#             */
/*   Updated: 2025/01/14 20:35:50 by wifons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_puthex(unsigned int n, int uppercase)
{
	char	*str;
	ssize_t	len;

	if (uppercase)
		str = ft_itoa_base(n, "0123456789ABCDEF");
	else
		str = ft_itoa_base(n, "0123456789abcdef");
	if (!str)
		return (-1);
	len = ft_putstr(str);
	free(str);
	return (len);
}
