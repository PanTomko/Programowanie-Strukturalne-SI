#include <stdio.h>
#include <stdlib.h>

int get_pessel_sum(char * p)
{
    return 9*(p[0]-48) + 7*(p[1]-48) + 3*(p[2]-48) + (p[3]-48) + 9*(p[4]-48)
              + 7*(p[5]-48) + 3*(p[6]-48) + (p[7]-48) + 9*(p[8]-48) + 7*(p[9]-48);
}

int is_pesel_valid(char * p)
{
    for(int i = 0; i < 11; i++)
        if(!(p[i] >= '0' && p[i] <= '9')) return 0;

    int sum = get_pessel_sum(p);

    printf("%d : ", (sum%10));
    return ((sum%10) == (p[10]-48));
}

int main()
{
    const char pesel_1[11] = "44051401358";
    const char pesel_2[11] = "99062324429";
    const char pesel_3[11] = "85072358457";
    const char pesel_4[11] = "89121909667";

    printf("PESEL 44051401358 : %d\n", is_pesel_valid(pesel_1));
    printf("PESEL 99062324429 : %d\n", is_pesel_valid(pesel_2));
    printf("PESEL 85072358457 : %d\n", is_pesel_valid(pesel_3));
    printf("PESEL 89121909667 : %d\n", is_pesel_valid(pesel_4));

    return 0;
}
