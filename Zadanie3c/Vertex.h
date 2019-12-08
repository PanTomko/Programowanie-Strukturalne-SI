#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED
#include "Edge.h"

struct Vertex;
typedef struct Vertex
{
    char symbol;
    struct Vertex *next;
    EdgeList edges;
}Vertex;

typedef struct VertexList
{
    int _count;
    Vertex *_begin;
    Vertex *_end;
}VertexList;

Vertex *push_vertex( VertexList *v_list, Vertex* vertex );
Edge *connect_vertex( Vertex * base, Vertex * connected, int weight);

#endif // VERTEX_H_INCLUDED
