#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main()
{
    unsigned int min = UINT_MAX, max = 0, tmp, res;
    for(;;)
    {
        res = scanf("%d", &tmp);
        if(res != 1)
        {
            printf("Max -> %d\n", max);
            printf("Min -> %d\n", min);
            break;
        }

        if(max < tmp) max = tmp;
        if(min > tmp) min = tmp;
    }

    return 0;
}
