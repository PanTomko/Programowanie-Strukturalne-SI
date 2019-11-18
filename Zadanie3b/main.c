#include <stdio.h>
#include <stdlib.h>

int pessel_get_day( char * pesel )
{
    return (10*(pesel[4] - 48)) +  (pesel[5] - 48);
}

int pessel_get_month( char * pesel )
{
    return ((10*(pesel[2] - 48)) +  (pesel[3] - 48)) % 20;
}

int pessel_get_year( char * pesel )
{
    int month = (10*(pesel[2] - 48)) +  (pesel[3] - 48);
    int year = (10*(pesel[0] - 48)) +  (pesel[1] - 48);
    int decade = month / 20;

    month = month % 20;

    if(decade == 8) year += 1800;
    else year += 1900 + ( 100 * decade );

    return year;
}

char pessel_get_gender( char * pesel )
{
    int num = (pesel[9] - 48) % 2;
    if( num == 0 ) return 'K';
    else return 'M';
}

int main()
{
    char pesel[11] = "02270803628";
    printf("Gender : %c\n",pessel_get_gender(pesel));
    printf("Date D-M-Y : [%.2d:%.2d:%d]",pessel_get_day(pesel), pessel_get_month(pesel), pessel_get_year(pesel));
    return 0;
}

