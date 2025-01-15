/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wifons <wifons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:49:12 by wifons            #+#    #+#             */
/*   Updated: 2025/01/14 20:28:27 by wifons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	char	*str;

	str = ft_itoa_base(42, "01");
	ft_putstr_fd(str, 1);
	free(str);
	ft_putchar_fd('\n', 1);
	str = ft_itoa_base(-255, "0123456789ABCDEF");
	ft_putstr_fd(str, 1);
	free(str);
	ft_putchar_fd('\n', 1);
	str = ft_itoa_base(0, "123456789");
	ft_putstr_fd(str, 1);
	free(str);
	ft_putchar_fd('\n', 1);
	return (0);
}
