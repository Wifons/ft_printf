/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wifons <wifons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:53:18 by wifons            #+#    #+#             */
/*   Updated: 2025/01/14 20:28:00 by wifons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	validate_base(const char *base, int *base_len)
{
	int	i;

	*base_len = ft_strlen(base);
	if (*base_len < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (!ft_isprint(base[i]) || ft_strchr(base + i + 1, base[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	handle_zero_case(char *result, long n, const char *base)
{
	if (n == 0)
	{
		result[0] = base[0];
		return (1);
	}
	return (0);
}

static long	handle_sign(char *result, long n)
{
	if (n < 0)
	{
		result[0] = '-';
		return (-n);
	}
	return (n);
}

char	*ft_itoa_base(int num, const char *base)
{
	int		base_len;
	int		n_len;
	char	*result;
	long	n;

	n = num;
	if (!validate_base(base, &base_len))
		return (NULL);
	n_len = ft_numlen_base(n, base_len);
	result = ft_calloc(n_len + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (handle_zero_case(result, n, base))
		return (result);
	n = handle_sign(result, n);
	while (n)
	{
		result[--n_len] = base[n % base_len];
		n /= base_len;
	}
	return (result);
}
