#include <stdio.h>
#include <string.h>

int	check_av(char *str)
{
	char	s[] = "23456789TJDKA";
	int		i;

	i = -1;
	while (str[++i])
	{
		if (!strchr(s, str[i]))
			return (0);
	}
	return (1);
}

int main(int ac, char **av)
{
	int	alredy_a;
	int	count;
	int	i;

	alredy_a = 0;
	count = 0;
	i = -1;
	if (ac == 2 && check_av(av[1]))
	{
		while (av[1][++i])
		{
			if (strchr("23456789", av[1][i]))
				count += (av[1][i] - '0');
			else if (strchr("TJDK", av[1][i]))
				count += 10;
			else if (av[1][i] == 'A')
			{
				if ((count + 11) < 21 && alredy_a == 0)
				{
					count += 11; 
					alredy_a = 1;
				}
				else
					count++;
			}
		}
		if (count == 21)
			printf("Blackjack!\n");
		else
			printf("%d\n", count);
	}
	else
		printf("Invalide argument!\n");
	return (0);
}
