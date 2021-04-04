/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_cp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 01:44:11 by yenam             #+#    #+#             */
/*   Updated: 2021/04/04 11:17:56 by hyojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

char	g_in[4][4];

bool	is_error(char *str);

void	put_char(void)
{
	int i;

	i = 0;
	while (i < 4)
	{
		write(1, g_in[i], 4);
		write(1, "\n", 1);
		i++;
	}
}

int		check(int x, int y, char **str)
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
	if (count == str[2][x])
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

int     fill_in(int x, int y,char **str)
{

	   int i;
	   int fillit;

	     if (y > 3)
		 {
			 x++;	
			 y = 0;
		 }
		 if (x > 3)
		{
		   return (1);

		}
		fillit = 0;
		 i = 1;
		 while (i < 5)
		 {
			g_in[x][y] = i + '0';
			 if (y == 3)
			 {
				if (is_duplicate(x, y) && check(x, y, str))
				 {
					  fillit = fill_in(x, y + 1, str);
					if (fillit)
						return (1);
				}
			 }	
			 else				
			 {
				  if (is_duplicate(x, y))
				  {
					 fillit = fill_in(x, y + 1, str);
						if (fillit)
					     return (1);
				}
			}
				 i++;
		 }

	    return (0);

}
/*int		fill_in(int x, int y, char **str)
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
		if ((is_duplicate(x, y) && check(x, y, str)) &&
				(fill_in(x, y + 1, str)) && (y == 3))
			return (1);
		else
		{
			if (is_duplicate(x, y) && (fill_in(x, y + 1, str)))
				return (1);
		}
	}
	return (0);
}*/



char	**ft_malloc(char **argv)
{
	char	**col_row;
	int		i;
	int		j;
	int		idx;

	col_row = (char **)malloc(sizeof(char *) * 4);
	i = 0;
	idx = 0;
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
	return (col_row);
}

int		main(int argc, char **argv)
{
	int		i;
	char	**str;

	i = 0;
	if (argc != 2 || is_error(argv[1]))
	{
		write(1, "Error", 5);
		return (-1);
	}
	str = ft_malloc(argv);
	fill_in(0, 0, str);
	i = 0;
	put_char();
	while (i < 4)
		free(str[i++]);
	free(str);
	return (0);
}
