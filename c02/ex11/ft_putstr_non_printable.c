/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinam <yejinam@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:49:17 by yejinam           #+#    #+#             */
/*   Updated: 2022/02/08 18:24:14 by yejinam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_printable(char c)
{
	if (32 <= c && c != 127)
		return (1);
	return (0);
}

void	ft_print_non_printable(char c)
{
	write(1, "\\", 1);
	write(1, &"0123456789abcdef"[c / 16], 1);
	write(1, &"0123456789abcdef"[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (ft_is_printable(*str))
			write(1, str, 1);
		else
			ft_print_non_printable(*str);
		str++;
	}
}
