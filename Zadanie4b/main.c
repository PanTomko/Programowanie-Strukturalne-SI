#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int get_pessel_sum(char * p)
{
    int sum = 9*(p[0]-48) + 7*(p[1]-48) + 3*(p[2]-48) + (p[3]-48) + 9*(p[4]-48)
              + 7*(p[5]-48) + 3*(p[6]-48) + (p[7]-48) + 9*(p[8]-48) + 7*(p[9]-48);
    return sum;
}

char* generate_password(char day[3], char month[3], char year[5], char gender)
{
    srand(time(0));

    int decade = 0;
    char year_2[5], month_2[2];
    memcpy(year_2, year, 4);

    char *tab = (char*)malloc(12* sizeof(char));

    memcpy(tab, year+2, 2);
    memcpy(tab+4, day, 2);

    if(atoi(year) < 1900) decade = 8;
    else
    {
        memset(year_2, '0', 1);
        decade = (atoi(year) - 1900) / 100;
        sprintf(month_2, "%d", atoi(month)+(decade*20));
        memcpy(tab+2,month_2, 2);
    }

    tab[6] = (rand() % 10) + 48;
    tab[7] = (rand() % 10) + 48;
    tab[8] = (rand() % 10) + 48;

    if( gender == 'K' ) while( (tab[9] = rand() % 10) % 2 == 0);
    else while( (tab[9] = rand() % 10) % 2 != 0);
    tab[9] += 48;
    tab[10] = 'n';

    tab[10] = (get_pessel_sum(tab)%10)+48;



    tab[11] = '\0';
    return tab;
}

int main()
{
    const char* pessel = generate_password("12", "11", "1922", 'M');

    printf("%s", pessel);
    return 0;
}
