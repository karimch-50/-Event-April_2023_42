#include <stdio.h>
#include <stdlib.h>

int	width_lenth(int i)
{
	if (i == 0)
		return (7);
	return (width_lenth(i - 1) + 2 * ((4 + i) + ((i % 2) + (i / 2))));
}

void	draw_stage(int h, int w, int s, int ok, int nbs)
{
	int i, j, k, l, m;

	i = -1;
	while (++i < h)
	{
		j = (-s) - 1;
		while (++j < (h - 1 - i))
			printf(" ");
		m = j;
		j += h - i;
		printf("/");
		k = ((w / 2) + 1) - ((nbs % 2) + (nbs / 2)) + 1 + m;
		l = ((w / 2) + 1) + ((nbs % 2) + (nbs / 2)) + m;
		while (++j < w)
		{
			if (ok == 1 && i >= !(nbs % 2) + 2 && j >= k && j < l)
			{
				k -= 1;
				while (++k < l)
					(nbs >= 5 && k == l - 2 && i == (nbs / 2) + 2) ? printf("$") : printf("|");
				j += l - k + 1;
			}
			printf("*");
		}
		printf("\\");
		printf("\n");
	}
}

int main(int ac, char **av)
{
	int	i;
	int	ok;
	int height;
	int	width;

	if (ac > 1)
	{
		i = -1;
		while (++i < atoi(av[1]))
		{
			height = 3 + i;
			width = width_lenth(i);
			ok = 0;
			if (i == atoi(av[1]) - 1)
				ok = 1;
			draw_stage(height, width, (width_lenth(atoi(av[1]) - 1) - width_lenth(i)) / 2, ok, atoi(av[1]));
		}
	}
	return (0);
}
