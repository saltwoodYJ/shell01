/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 04:28:40 by hyojlee           #+#    #+#             */
/*   Updated: 2021/04/04 05:03:04 by hyojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char	g_result[4][4];

bool	is_chk_row(char *str, char n1, char n2);

int		is_dup(int x, int y);

bool	is_chk_col(char **str, int row, char n1, char n2);

void	ft_comb(int i, int j, char **str)
{
	while (g_result[i][j] < '5')
	{
		if (j == 3)
		{
			if (is_dup(i, j))
			{
				if(is_chk_row(g_result[i], str[2][i], str[3][i]) == true)
				{
					i++;
					return ;
				}
			}
		}
		g_result[i][j]++;
		if (j < 3)
			ft_comb(i, j + 1, str);
	}
	if (j < 3)
	g_result[i][j + 1] = '1';
}

void	ft_first_comb(char **str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (k < 4)
	{
		while (g_result[i][j] < '5')
		{
			g_result[i][j]++;
			ft_comb(i, j + 1, str);
		}
		g_result[i][j + 1] = '1';
		k++;
		i++;
	}
}

void	print(void)
{
	write(1, g_result[0], 4);
	write(1, "\n", 1);
	write(1, g_result[1], 4);
	write(1, "\n", 1);
	write(1, g_result[2], 4);
	write(1, "\n", 1);
	write(1, g_result[3], 4);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	char	**col_row;
	int		i;
	int		j;
	int		idx;

	i = 0;
	idx = 0;
//	if (argc != 2 || is_error(argv[1]))
//	{
//		write(1, "Error", 5);
//		return -1;
//	}
	if (argc == 2)
	{
		col_row = (char **)malloc(sizeof(char *) * 4);
		while (i < 4)
		{
			col_row[i] = (char *)malloc(sizeof(char) * 4);
			j = 0;
			while (j < 4)
			{
				col_row[i][j++] = argv[1][idx];
				idx += 2;
			}
			i++;
		}
		ft_first_comb(col_row);
		print();
	}
	return (0);
}
