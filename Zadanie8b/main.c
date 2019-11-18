#include <stdio.h>
#include <stdlib.h>

void swap(int * n1, int * n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void quick_sort( int *tab, int left, int right )
{
    int i = left, j = right;
    int x = tab[( left + right ) / 2 ];
    do
    {
        while( tab[ i ] < x )
             i++;

        while( tab[ j ] > x )
             j--;

        if( i <= j )
        {
            swap( &tab[ i ], &tab[ j ] );
            i++;
            j--;
        }
    } while( i <= j );

    if( right > i ) quick_sort( tab, i, right );
    if( left < j ) quick_sort( tab, left, j );

}

int main()
{
    int tab_1[10] = {10, 2, 23, 2, 21, 1, 8, 6, 4, 2};
    quick_sort(tab_1, 0, 9);
    for(int i = 0; i < 10; i++) printf("%d, ", tab_1[i]);
    printf("\n");
    return 0;
}
