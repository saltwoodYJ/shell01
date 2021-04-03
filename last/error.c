/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 08:16:50 by hyojlee           #+#    #+#             */
/*   Updated: 2021/04/04 08:25:46 by hyojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

extern	char	g_in[4][4];

int		ft_strlen(char *str)
{
	int cnt;

	cnt = 0;
	while (*str++ != '\0')
		cnt++;
	return (cnt);
}

int		absol_val(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

bool	is_error(char *argv)
{
	if (ft_strlen(argv) != 31)
		return (true);
	while (*argv != '\0')
	{
		if (*argv != ' ' && (*argv < '1' || *argv > '4'))
			return (true);
		argv++;
	}
	return (false);
}

bool	is_error_array(char *col1, char *col2)
{
	int idx;
	int sub;

	idx = 0;
	while (idx < 4)
	{
		sub = col1[idx] - col2[idx];
		if (sub == 0 && col1[idx] != '2')
			return (true);
		else if (col1[idx] == '4' || col2[idx] == '4')
		{
			if (absol_val(sub) != 3)
				return (true);
		}
		idx++;
	}
	return (false);
}
