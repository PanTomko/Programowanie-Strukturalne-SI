#include <stdio.h>
#include <stdlib.h>

int is_pesel_valid(char * p)
{
    for(int i = 0; i < 11; i++)
        if(!(p[i] >= '0' && p[i] <= '9')) return 0;

    int sum = 9*(p[0]-48) + 7*(p[1]-48) + 3*(p[2]-48) + (p[3]-48) + 9*(p[4]-48)
              + 7*(p[5]-48) + 3*(p[6]-48) + (p[7]-48) + 9*(p[8]-48) + 7*(p[9]-48);

    printf("%d : ", (sum%10));
    return ((sum%10) == (p[10]-48));
}

int main()
{
    char pesel_1[11] = "44051401358";
    char pesel_2[11] = "99062324429";
    char pesel_3[11] = "85072358457";
    char pesel_4[11] = "79103184247";

    printf("PESEL 44051401358 : %d\n", is_pesel_valid(pesel_1));
    printf("PESEL 99062324429 : %d\n", is_pesel_valid(pesel_2));
    printf("PESEL 85072358457 : %d\n", is_pesel_valid(pesel_3));
    printf("PESEL 79103184247 : %d\n", is_pesel_valid(pesel_4));

    return 0;
}
