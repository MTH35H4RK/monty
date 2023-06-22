#include "monty.h"

int is_number(const char *str)
{
    int i = 0;
    int length = strlen(str);

    if (str == NULL || *str == '\0')
        return 0;

    /* Check for negative sign */
    if (str[0] == '-')
        i = 1;

    /* Check if all characters are digits */
    for (; i < length; i++)
    {
        if (!isdigit((unsigned char)str[i]))
            return 0;
    }

    return 1;
}
