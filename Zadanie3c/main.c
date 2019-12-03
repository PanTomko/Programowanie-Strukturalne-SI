#include <stdio.h>
#include <stdlib.h>

struct Vertex;

typedef struct Edge
{
    struct Vertex * connection;
    unsigned int ;
}Edge;

typedef struct Vertex
{
    char symbol;
    struct Vertex *next;
}Vertex;

typedef struct VertexList
{
    int count;
    Vertex *begin;
    Vertex *end;
}VertexList;

typedef struct Graf
{
    VertexList vertexs;
}Graf;

void ini_graf(Graf *graf, Vertex *head )
{
    if( head != NULL ) graf->vertexs.count++;
    graf->vertexs.begin = head;
    graf->vertexs.end = head;
    head->next = NULL;
}

void clear(Graf *graf)
{

}

void add_vertex( Graf *graf, Vertex *vertex )
{
    if( graf->vertexs.end == NULL )
    {
        graf->vertexs.begin = vertex;
        graf->vertexs.end = vertex;
    }
    else
    {
        vertex->next = NULL;
        graf->vertexs.end->next = vertex;
        graf->vertexs.end = vertex;
    }
    graf->vertexs.count++;
}

void add_vertex_copy( Graf *graf, Vertex vertex )
{
    Vertex *tmp = malloc(sizeof(Vertex));
    *tmp = vertex;
    add_vertex(graf, tmp);
}

void print_graf( Graf *graf )
{
    for(Vertex * it = graf->vertexs.begin; it != NULL; it = it->next)
    {
        printf("%c\n", it->symbol);
    }
}

struct xd{
    int x;
};

void xde( struct xd XD){
    printf("XD !");
}

int main()
{
    Vertex *v1 = malloc(sizeof(Vertex));
    v1->symbol = '1';

    Vertex *v2 = malloc(sizeof(Vertex));
    v2->symbol = '2';

    Graf graf;
    ini_graf(&graf, v1);
    add_vertex(&graf, v2);
    //add_vertex_copy(&graf, struct Vertex{'s', NULL});
    xde(struct xd{1});
    print_graf(&graf);
    return 0;
}
