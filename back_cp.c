/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_cp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 01:44:11 by yenam             #+#    #+#             */
/*   Updated: 2021/04/04 08:50:33 by yenam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char		g_in[4][4];

int		g_col_row[4][4];

int		check(int x, int y)
{
	int i;
	int j;
	int count;

	i = 0;
	j = i + 1;
	count = 1;
	while (j <= y)
	{
		if (g_in[x][i] < g_in[x][j])
		{
			count++;
			i = j;
		}
		j++;
	}
	if (count == g_col_row[2][x])
		return (1);
	return (0);
}

int		is_duplicate(int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < y)
	{
		j = i + 1;
		while (j <= y)
		{
			if (g_in[x][++i] == g_in[x][++j])
				return (0);
		}
	}
	i = 0;
	while (i < x)
	{
		j = i + 1;
		while (j <= x)
		{
			if (g_in[++i][y] == g_in[++j][y])
				return (0);
		}
	}
	return (0);
}

int		fill_in(int x, int y)
{
	int i;
	int fillit;

	if (y > 3)
	{
		x++;
		y = 0;
	}
	if (x > 3)
		return (1);
	fillit = 0;
	i = 0;
	while (++i < 5)
	{
		g_in[x][y] = i + '0';
		if ((is_duplicate(x, y) && check(x, y)) &&
				(fill_in(x, y + 1)) && (y == 3))
			return (1);
		else
		{
			if (is_duplicate(x, y) && (fill_in(x, y + 1)))
				return (1);
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	fill_in(0, 0);
	while (i < 4)
	{
		write(1, g_in[i], 4);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
