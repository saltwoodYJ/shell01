/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_check_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 03:51:28 by hyojlee           #+#    #+#             */
/*   Updated: 2021/04/04 04:54:14 by hyojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

extern	char	g_result[4][4];

bool	is_chk_col(char **str, int row, char n1, char n2)
{
	int		idx;
	char	cnt;
	char	base;
	bool	flag;

	cnt = '1';
	idx = 0;
	flag = false;
	base = str[row][idx++];
	while (idx < 4)
	{
		if (base < str[row][idx])
		{
			cnt++;
			base = str[row][idx];
		}
		idx++;
	}
	if (cnt == n1)
		flag = true;
	base = str[row][--idx];
	cnt = '1';
	while (idx > 0)
	{
		if (base < str[row][--idx])
		{
			cnt++;
			base = str[row][idx];
		}
	}
	if (cnt == n2 && flag)
		return (true);
	return (false);
}

int is_dup(int x, int y)
{
	int i;
	int j;

	i = 0;
	while(i < y)
	{
		j = i+1;
		while(j <= y)
		{
			if(g_result[x][i] == g_result[x][j])
				return 0;
			j++;
		}
		i++;
	}
	return 1;

}

bool	is_chk_row(char *str, char n1, char n2)
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
