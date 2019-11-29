#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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
    unsigned int count = 0, current_szie = 0, tmp, res;
    unsigned int * numbers = NULL;
    for(;;)
    {
        res = scanf("%d", &tmp);
        if(res < 1)
        {
            quick_sort(numbers, 0, count-1);
            printf("Min -> %d\n", numbers[0]);
            printf("Max -> %d\n", numbers[count-1]);
            break;
        }

        count += 1;
        if( count > current_szie ){
            numbers = realloc(numbers, sizeof(unsigned int) * (current_szie+10) );
            current_szie+=10;
        }

        numbers[count-1] = tmp;

    }

    return 0;
}
