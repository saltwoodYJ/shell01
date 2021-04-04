/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojlee <hyojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:58:08 by hyojlee           #+#    #+#             */
/*   Updated: 2021/04/03 22:47:57 by hyojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

char	g_result[4][4];

void	fill_col_4(int row_index, int index);
void	fill_row_4(int col_index, int index);

void	init(void)
{
	int i=0;
	int j;
	while(i < 4)
	{
		j=0;
		while(j < 4)
		{
			g_result[i][j] = '0';
			j++;
		}
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

void	fill_col(char *str, int index)
{
	int row_index = 0;
	while (row_index < 4)
	{
		if (str[row_index] == '1')
		{
			g_result[index][row_index] = '4';
		}
		if (str[row_index] == '4')
		{
			fill_col_4(row_index, index);
		}
		row_index++;
	}
}

void	fill_col_4(int col_index, int flag)
{
	if (flag == 0)
	{
		g_result[0][col_index] = '1';
		g_result[1][col_index] = '2';
		g_result[2][col_index] = '3';	
		g_result[3][col_index] = '4';
	}
	if (flag == 3)
	{
		g_result[0][col_index] = '4';
		g_result[1][col_index] = '3';
		g_result[2][col_index] = '2';
		g_result[3][col_index] = '1';
	}
}

void	fill_row(char *str, int index)
{
	int col_index = 0;
	while (col_index < 4)
	{
		if (str[col_index] == '1')
		{
			g_result[col_index][index] = '4';
		}
		if (str[col_index] == '4')
		{
			fill_row_4(col_index, index);
		}
		col_index++;
	}
}

void	fill_row_4(int row_index, int flag)
{
	if (flag == 0)
	{
		g_result[row_index][0] = '1';
		g_result[row_index][1] = '2';
		g_result[row_index][2] = '3';
		g_result[row_index][3] = '4';
	}
	if (flag == 3)
	{
		g_result[row_index][0] = '4';
		g_result[row_index][1] = '3';
		g_result[row_index][2] = '2';
		g_result[row_index][3] = '1';
	}
}

void	re_col(char *str1, char *str2)
{
	int index = 0;
	while (index < 4)
	{
		if (str1[index] == '1' && str2[index] == '2')
			g_result[3][index] = '3';
		else if (str1[index] == '2' && str2[index] == '1')
			g_result[0][index] = '3';
		else if (str1[index] == '2' && str2[index] == '3')
			g_result[1][index] = '4';
		else if (str1[index] == '3' && str2[index] == '2')
			g_result[2][index] = '4';
		index++;
	}
}

void	re_row(char *str1, char *str2)
{
	int index = 0;
	while (index < 4)
	{
		if (str1[index] == '1' && str2[index] == '2')
			g_result[index][3] = '3';
		else if (str1[index] == '2' && str2[index] == '1')
			g_result[index][0] = '3';
		else if (str1[index] == '2' && str2[index] == '3')
			g_result[index][1] = '4';
		else if (str1[index] == '3' && str2[index] == '2')
			g_result[index][2] = '4';
		index++;
	}
}

int		ft_strlen(char *str)
{
	int cnt;

	cnt = 0;
	while (*str++ != '\0')
		cnt++;
	return (cnt);
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

int		absol_val(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
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

bool	compare_row(void)
{
	int mul;
	int sum;
	int i;
	int j;
	int temp;

	i = 0;
	while (i < 4)
	{
		j = 0;
		sum = 0;
		mul = 1;
		while (j < 4)
		{
			temp = g_result[i][j++] - '0';
			sum += temp;
			mul *= temp;
		}
		if (sum != 10 || mul != 24)
			return (true);
		i++;
	}
	return (false);
}

bool	compare_col(void)
{
	int mul;
	int sum;
	int i;
	int j;
	int temp;

	i = 0;
	while (i < 4)
	{
		j = 0;
		sum = 0;
		mul = 1;
		while (j < 4)
		{
			temp = g_result[j++][i] - '0';
			sum += temp;
			mul *= temp;
		}
		if (sum != 10 || mul != 24)
			return (true);
		i++;
	}
	return (false);
}

int		main(int argc, char **argv)
{
	char	**col_row;
	int		i;
	int		j;
	int		idx;

	i = 0;
	idx = 0;
	if (argc != 2 || is_error(argv[1]))
	{
		write(1, "Error", 5);
		return -1;
	}
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
	init();
	fill_col(col_row[0], 0);
	fill_col(col_row[1], 3);
	fill_row(col_row[2], 0);
	fill_row(col_row[3], 3);
	re_col(col_row[0], col_row[1]);
	re_row(col_row[2], col_row[3]);
	print();
	
	i = 0;
	while (i < 4)
		free(col_row[i++]);
	free(col_row);
	return (0);
}
