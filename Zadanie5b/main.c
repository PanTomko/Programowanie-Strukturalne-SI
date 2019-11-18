#include <stdio.h>
#include <stdlib.h>

void swap(int * n1, int * n2){
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void bubble_sort(int *tab, int size)
{
    size -= 1;

    for(int i = 0; i < size; i++)
        for(int j = 0; j < size - i; j++)
            if(tab[j] > tab[j+1])
                swap(&tab[j], &tab[j+1]);
}

void bubble_sort_boolean(int *tab, int size) {
    int swapped = 1, j = 0;

    while (swapped)
    {
        swapped = 0;
        j++;

        for (int i = 0; i < size - j; i++)
            if (tab[i] > tab[i + 1])
            {
                swap(&tab[i], &tab[i+1]);
                swapped = 1;
            }
    }
}

void bubble_sort_optimal(int *tab, int size) {
    int last_swap = size - 1;

    for(int i = 1; i < size; i++)
    {
        int is_sorted = 1;
        int current_swap = -1;

        for(int j=0; j < last_swap; j++)
            if(tab[j] > tab[j+1])
            {
                swap(&tab[j], &tab[j+1]);
                is_sorted = 0;
                current_swap = j;
            }

        if(is_sorted) return;
        last_swap = current_swap;
    }
}

int main()
{
    int tab_1[10] = {3, 2, 1, 2, 3, 4, 2, 1, 9, 7};
    int tab_2[10] = {3, 2, 1, 2, 3, 4, 2, 1, 9, 7};
    int tab_3[10] = {3, 2, 1, 2, 3, 4, 2, 1, 9, 7};

    bubble_sort(tab_1, 10);
    for(int i = 0; i < 10; i++) printf("%d, ", tab_1[i]);
    printf("\n");

    bubble_sort_boolean(tab_2, 10);
    for(int i = 0; i < 10; i++) printf("%d, ", tab_2[i]);

    printf("\n");

    bubble_sort_optimal(tab_3, 10);
    for(int i = 0; i < 10; i++) printf("%d, ", tab_3[i]);
    printf("\n");

    return 0;
}
