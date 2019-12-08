#include "Graf.h"

#include <stdlib.h>
#include <stdio.h>

void ini_graf(Graf *graf, Vertex *head )
{
    if( head != NULL )
    {
        graf->vertexs._count++;
        head->next = NULL;
    }

    graf->vertexs._begin = head;
    graf->vertexs._end = head;
    graf->vertexs._count = 0;
}

void print_graf( Graf *graf )
{
    for(Vertex * it = graf->vertexs._begin; it != NULL; it = it->next)
    {
        printf("%c -> | ", it->symbol);
        for(Edge * it2 = it->edges._begin; it2 != NULL; it2 = it2->next)
        {
            printf("%c:%d | ", it2->connection->symbol, it2->G);
        }
        printf("\n");
    }
}

Vertex *graf_add_vertex( Graf *graf, char symbol )
{
    Vertex * tmp = (Vertex*)malloc(sizeof(Vertex));
    tmp->symbol = symbol;
    tmp->edges._begin = NULL;
    tmp->edges._end = NULL;
    tmp->edges._count = 0;


    push_vertex(&graf->vertexs, tmp);
    return tmp;
}
