#include "../includes/minirt.h"

int is_in_set(char c)
{
    int j;

    j = -1;
    while (SPLIT_SET[++j])
    {
        if (c == SPLIT_SET[j])
            return (1);
    }
    return (0);
}