/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 03:05:21 by hyojlee           #+#    #+#             */
/*   Updated: 2021/04/04 03:37:43 by hyojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int		ft_strlen(char *str)
{
	int cnt;

	cnt = 0;
	while (*str++ != '\0')
		cnt++;
	return (cnt);
}

bool	is_dup(char *str)
{
	int	idx;
	int j;

	idx = 0;
	while (idx < 4)
	{
		j = idx + 1;
		while (j < 4)
		{
			if (str[idx] == str[j++])
				return (false);
		}
		idx++;
	}
	return (true);
}

bool	is_check(char *str, char n1, char n2)
{
	char	cnt;
	char	base;
	bool	flag;
	int		idx;

	cnt = '1';
	flag = false;
	idx = 0;
	base = str[idx++];
	while (idx < 4)
	{
		if (base < str[idx])
		{
			cnt++;
			base = str[idx];
		}
		idx++;
	}
	if (cnt == n1)
		flag = true;
	base = str[--idx];
	cnt = '1';
	while (idx > 0)
	{
		if (base < str[--idx])
		{
			cnt++;
			base = str[idx];
		}
	}
	if (cnt == n2 && flag)
		return (true);
	return (false);
}
