#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED
#include "Vertex.h"

typedef struct Graf
{
    VertexList vertexs;
}Graf;

void ini_graf( Graf *graf, Vertex *head );
void print_graf( Graf *graf );
Vertex *graf_add_vertex( Graf *graf, char symbol );

#endif // GRAF_H_INCLUDED
