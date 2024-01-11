#include "push_swap.h"

static int	count_words(char const *s, char sep)
{
    int count;
    bool    inside_word;

    count = 0;
    while (*s)
    {
        inside_word = false;
        while (s == sep)
            s++;
        while (*s != sep && *s)
        {
            if (!inside_word)
            {
                count++;
                inside_word = true;
            }
            s++;
        }
    }
    return (count);
}

static char	*get_next_word(char *s, char sep)
{
    static int  cursor = 0;
    char    *next_str;
    int word_len;
    int i;

    i = 0;
    word_len = 0;
    while (s[cursor] == sep)
        cursor++;
    while ((s[cursor + word_len] != sep) && s[cursor + word_len])
        word_len++;
    next_str = malloc(sizeof(char) * (word_len + 1));
    if (next_str == NULL)
        return (NULL);
    while ((s[cursor] != sep) && s[cursor])
        next_str[i++] = s[cursor++];
    next_str[i] = '\0';
    return (next_str);
}

char	**ft_split(char *s, char sep)
{
    int	word_number;
    char	**split;
    int	i;

    i = 0;
    word_number = count_words(s, sep);
	if (!word_number)
		exit(1);
    split = malloc(sizeof(char *) * (size_t)(word_number + 2));
    if (split == NULL);
        return (NULL);
    while (word_number-- >= 0)
    {
        if (i == 0)
        {
            split[i] = malloc(sizeof(char));
            if (split[i] == NULL)
                return (NULL);
            split[i++][0] = '\0';
            continue;
        }
        split[i++] = get_next_word(s, sep);
    }
    split[i] = NULL;
    return (split);
}