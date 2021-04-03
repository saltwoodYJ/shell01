#include <unistd.h>
#include <stdio.h>

int		g_result[4][4];

void	ft_comb(int i, int j)
{
	while (g_result[i][j] < 5)
	{
		if(j == 3)
		{
			if (dup() == true)
			{
				if(chk() == true)
				{
					i++;
					return ;
				}
			}
		}
		g_result[i][j]++;
		if (j < 3)
			ft_comb(i, j + 1);
	}
	if (j < 3)
	g_result[i][j+1] = 1;
}

void	ft_first_comb(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (k < 4)
	{
		while (g_result[i][j] < 5)
		{
			g_result[i][j]++;
			ft_comb(i, j + 1);
		}
		g_result[i][j+1] = 1;
		k++;
		i++;
	}
}

int		main(void)
{
	ft_first_comb();
//	write(1, g_result[0], 4);
	printf("%d",g_result[0]);
	write(1, "\n", 1);
//	write(1, g_result[1], 4);
	printf("%d",g_result[1]);
	write(1, "\n", 1);
//	write(1, g_result[2], 4);
	printf("%d",g_result[2]);
	write(1, "\n", 1);
//	write(1, g_result[3], 4);
	printf("%d",g_result[3]);
	write(1, "\n", 1);
	return 0;
}
