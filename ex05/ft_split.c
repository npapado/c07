#include <stdlib.h>

char    **ft_split(char *str, char *charset)
{
    char    **result;
    char    *temp;
    int     word_count;
    int     i;
    int     j;
    int     k;
    int     start;
    int     in_word;
    int     result_size;

    result_size = 1;
    result = (char **)malloc(sizeof(char *) * result_size);
    word_count = 0;
    i = 0;
    in_word = 0;

    while (str[i])
    {
        k = 0;
        while (charset[k] && str[i] != charset[k])
        {
            k++;
        }

        if (!charset[k])
        {
            if (!in_word)
            {
                start = i;
                in_word = 1;
            }
        }
        else
        {
            if (in_word)
            {
                in_word = 0;
                temp = (char *)malloc(i - start + 1);

                j = 0;
                while (start < i)
                {
                    temp[j++] = str[start++];
                }

                temp[j] = '\0';

                if (word_count + 2 > result_size)
                {
                    result_size *= 2;
                    char **new_result = (char **)malloc(sizeof(char *) * result_size);
                    j = 0;
                    while (j < word_count)
                    {
                        new_result[j] = result[j];
                        j++;
                    }
                    free(result);
                    result = new_result;
                }

                result[word_count++] = temp;
            }
        }

        i++;
    }

    if (in_word)
    {
        temp = (char *)malloc(i - start + 1);

        j = 0;
        while (start < i)
        {
            temp[j++] = str[start++];
        }

        temp[j] = '\0';

        if (word_count + 2 > result_size)
        {
            result_size *= 2;
            char **new_result = (char **)malloc(sizeof(char *) * result_size);
            j = 0;
            while (j < word_count)
            {
                new_result[j] = result[j];
                j++;
            }
            free(result);
            result = new_result;
        }

        result[word_count++] = temp;
    }

    if (word_count + 1 > result_size)
    {
        char **new_result = (char **)malloc(sizeof(char *) * (word_count + 1));
        j = 0;
        while (j < word_count)
        {
            new_result[j] = result[j];
            j++;
        }
        free(result);
        result = new_result;
    }

    result[word_count] = 0;

    return (result);
}
