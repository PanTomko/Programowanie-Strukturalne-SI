#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *tab, int size)
{
    int tmp, j;
    for(int i = 0; i < size; i++)
    {
        tmp = tab[i];
        for (j = i - 1; j >= 0 && tab[j] > tmp; j--)
        {
            tab[j+1] = tab[j];
        }
        tab[j+1] = tmp;
    }
}

int main()
{
    int tab_1[10] = {10, 2, 23, 2, 21, 1, 8, 6, 4, 2};

    insertion_sort(tab_1, 10);
    for(int i = 0; i < 10; i++) printf("%d, ", tab_1[i]);
    printf("\n");

    return 0;
}
