#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_pesel_sum(char * p)
{
    return 9*(p[0]-48) + 7*(p[1]-48) + 3*(p[2]-48) + (p[3]-48) + 9*(p[4]-48)
              + 7*(p[5]-48) + 3*(p[6]-48) + (p[7]-48) + 9*(p[8]-48) + 7*(p[9]-48);
}

int is_pesel_valid(char * p)
{
    int good_day = 0;
    for(int i = 0; i < 11; i++)
        if(!(p[i] >= '0' && p[i] <= '9')) return 0;

    int sum = get_pesel_sum(p);
    return ((sum%10) == (p[10]-48));
}

char pessel_get_gender( char * pesel )
{
    int num = (pesel[9] - 48) % 2;
    if( num == 0 ) return 'K';
    else return 'M';
}

typedef struct Record
{
    char name[15];
    char lastName[20];
    char address[40];
    char city[15];
    char phone[10];
    char pesel[12];

    struct Record* prev;
    struct Record* next;
}Record;

typedef struct Baza
{
    int count;

    Record* end;
    Record* begin;
}Baza;

void BazaIni(Baza *baza)
{
    baza->count = 0;
    baza->begin = NULL;
    baza->end = NULL;
}

void BazaClear(Baza* baza)
{
    Record * tmp = NULL;
    for(Record * it = baza->begin; it != NULL; )
    {
        free(tmp);
        tmp = it;
        it = it->next;
    }
}

int BazaPeselExist(Baza* baza, char pesel[12])
{
    for(Record * it = baza->begin; it != NULL; it = it->next)
    {
        if(!strcmp(it->pesel, pesel)) return 1;
    }
    return 0;
}

int BazaAddRecord(Baza* baza,
    char name[15],
    char lastName[20],
    char address[40],
    char city[15],
    char phone[10],
    char pesel[12])
{
    if(!is_pesel_valid(pesel)) return -1;
    if(BazaPeselExist(baza, pesel)) return -1;

    Record* record = (Record*)malloc(sizeof(Record));
    strcpy(record->name, name);
    strcpy(record->lastName, lastName);
    strcpy(record->address, address);
    strcpy(record->city, city);
    strcpy(record->phone, phone);
    strcpy(record->pesel, pesel);

    if( baza->begin == NULL)
        baza->begin = record;

    if(baza->end == NULL)
        baza->end = record;
    else
    {
        record->prev = baza->end;
        baza->end->next = record;
        baza->end = record;
    }

    record->next = NULL;
    baza->count++;
    return 1;
}

void BazaPrintRecord(Record* record)
{
    printf(" -- %s %s -- \n", record->name, record->lastName);
    printf("  addres : %s \n", record->address);
    printf("  city   : %s \n", record->city);
    printf("  phone  : %s \n", record->phone);
    printf("  pesel  : %s \n\n", record->pesel);
}

void BazaPrintAll(Baza* baza)
{
    for(Record * it = baza->begin; it != NULL; it = it->next)
    {
        BazaPrintRecord(it);
    }
}

void BazaPrint(Baza* baza, int (*cmp)(Record*))
{
    for(Record * it = baza->begin; it != NULL; it = it->next)
    {
        if(cmp(it)) BazaPrintRecord(it);
    }
}

// my cmp
int cmp_getByCity(Record* record)
{
    if(!strcmp(record->city, "Walcz")) return 1;
    else return 0;
}


int main()
{
    Baza baza;
    BazaIni(&baza);

    BazaAddRecord(&baza,
                  "Tomek",
                  "Zaskorski",
                  "Wojska Polskiego 30/3",
                  "Walcz",
                  "666666666",
                  "81060156713");

    BazaAddRecord(&baza,
                  "Grol",
                  "Bola",
                  "FF 15 GG/BG",
                  "Planeta X",
                  "666666666",
                  "79061283934");

    BazaAddRecord(&baza,
                  "Grol",
                  "Bola",
                  "FF 15 GG/BG",
                  "Planeta X",
                  "666666666",
                  "79061283934");

    BazaAddRecord(&baza,
                  "Ala",
                  "Ma",
                  "Kota Polskiego 10/9",
                  "Walcz",
                  "646464646",
                  "95021436369");


    printf("%d \n", BazaPeselExist(&baza, "81060156713"));

    puts("================================");
    BazaPrintAll(&baza);
    puts("================================");

    BazaPrint(&baza, cmp_getByCity);
    puts("================================");

    for(Record * it = baza.begin; it != NULL; it = it->next)
    {
        if(!strcmp(it->city, "Walcz") && pessel_get_gender(it->pesel) == 'M')
        {
            BazaPrintRecord(it);
        }
    }
    puts("================================");

    BazaClear(&baza);
    return 0;
}
