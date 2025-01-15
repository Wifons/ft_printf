/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wifons <wifons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:20:15 by wifons            #+#    #+#             */
/*   Updated: 2025/01/14 20:20:21 by wifons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbr(int n)
{
	char	*str;
	ssize_t	len;

	str = ft_itoa(n);
	if (!str)
		return (-1);
	len = ft_putstr(str);
	free(str);
	return (len);
}
