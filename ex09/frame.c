#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int	word_count(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static char	*alloc_word_mem(char *str, char c)
{
	int		i;
	int		count_letters;
	char	*ret_word;

	count_letters = 0;
	while (str[count_letters] != c && str[count_letters])
		count_letters++;
	ret_word = (char *)malloc(count_letters * sizeof(char) + 1);
	if (!ret_word)
		return (0);
	i = 0;
	while (i < count_letters)
	{
		ret_word[i] = str[i];
		i++;
	}
	ret_word[i] = '\0';
	return (ret_word);
}

char	**mem_free(char **ret, int j)
{
	while (j > 0)
	{
		j--;
		free(ret[j]);
	}
	free(ret);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret_split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret_split = malloc(sizeof(char *) * (word_count((char *)s, c) + 1));
	if (!ret_split)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			ret_split[j] = alloc_word_mem((char *)&s[i], c);
			if (!ret_split[j])
				return (mem_free(ret_split, j));
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	ret_split[j] = 0;
	return (ret_split);
}

void	line_h_w(int *h, int *w, char *str)
{
	char	**word;
	int		i;
	int		w_count;

	i = -1;
	w_count = 0;
 	word = ft_split(str, ' ');
	while (word[++i])
	{
		if (w_count < strlen(word[i]))
			w_count = strlen(word[i]);
		(*h)++;
	}
	*w = w_count;
}

void	print_etoil(int nb)
{
	int i;

	i = -1;
	while (++i < nb)
		printf("*");
	printf("\n");
}

void	print_space(int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
		printf(" ");
	printf(" *\n");
}

int main(int ac, char **av)
{
	char **word;
	int	h;
	int	w;
	int	i;

	if (ac == 2)
	{
		line_h_w(&h, &w, av[1]);
		print_etoil(w + 4);
    	i = -1;
		word = ft_split(av[1], ' ');
    	while (word[++i])
    	{
    	    printf("* %s", word[i]);
			if (strlen(word[i]) == w) 
				printf(" *\n");
			else
				print_space(w - strlen(word[i]));
    	}
		print_etoil(w + 4);
	}
	return (0);
}