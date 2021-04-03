/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_check_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 03:51:28 by hyojlee           #+#    #+#             */
/*   Updated: 2021/04/04 04:08:30 by hyojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_check_col(char **str, int row, char n1, char n2)
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
