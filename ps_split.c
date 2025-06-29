#include "ps_header.h"

static int	one_word_len(char const *s, char sep)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i] && s[i] != sep)
		i++;
	return (i);
}

static char	*ps_substr(char const *s, unsigned int start, size_t len)
{
	char	*baby;
	size_t	i;

	if (s == 0)
		return (NULL);
	baby = malloc((len + 1) * sizeof(char));
	if (baby == NULL)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		baby[i++] = s[start++];
		len--;
	}
	baby[i] = '\0';
	return (baby);
}

static size_t	number_of_words(char const *s, char sep)
{
	size_t	count;
	size_t	start_word;

	if (s == NULL)
		return (0);
	start_word = 0;
	count = 0;
	while (*s)
	{
		if (*s != sep && start_word == 0)
		{
			start_word = 1;
			count++;
		}
		if (*s == sep)
			start_word = 0;
		s++;
	}
	return (count);
}

static void	*cleanup(char **arr_of_pointers, int i)
{
	while (i >= 0)
	{
		free (arr_of_pointers[i]);
		arr_of_pointers[i] = NULL;
		i--;
	}
	return (NULL);
}

char	**ps_split(char const *s, char sep)
{
	char	**splitted;
	size_t	words;
	size_t	i;

	words = number_of_words(s, sep);
	splitted = malloc((words + 1) * sizeof(char *));
	if (splitted == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != sep)
		{
			splitted[i] = ps_substr(s, 0, one_word_len(s, sep));
			if (splitted == NULL)
				return (cleanup(splitted, i));
			s += one_word_len(s, sep);
			i++;
		}
		else
			s++;
	}
	splitted[i] = NULL;
	return (splitted);
}
