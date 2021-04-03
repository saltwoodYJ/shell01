/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 01:44:11 by yenam             #+#    #+#             */
/*   Updated: 2021/04/04 04:23:54 by yenam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char g_in[4][4];

int is_duplicate(int x, int y)
{
	int i;
	int j;

	i = 0;
	while(i < y)
	{
		j = i+1;
		while(j <= y)
		{
			if(g_in[x][i] == g_in[x][j])
				return 0;
			j++;
		}
		i++;
	}
	return 1;

}

int fill_in(int x, int y)
{
	int i;

	if(y > 3)
	{
		x++;
		y=0;
	}
	if(x > 3)
	{
		return 0;
	}

	i = 1;
	while(i < 5)
	{
		g_in[x][y] = i + '0';
		if(is_duplicate(x, y))
		{
			fill_in(x, y+1);
			return 0;
		}
		i++;
	}

	return 0;
}


int main(int argc, char ** argv)
{
	int i = 0;

	fill_in(0,0);
	while(i < 4)
	{
		write(1, g_in[i],4);
		write(1, "\n", 1);
		i++;

	}

	return 0;
}
