#include "Vertex.h"
//#include "Edge.h"

#include <stdlib.h>

Vertex *push_vertex( VertexList *v_list, Vertex* vertex )
{
    vertex->next = NULL;

    if(v_list->_begin == NULL)
        v_list->_begin = vertex;
    else
        v_list->_end->next = vertex;

    v_list->_end = vertex;

    v_list->_count++;
    return vertex;
}

Edge *connect_vertex( Vertex * base, Vertex * connected, int weight)
{
    Edge *tmp = (Edge*)malloc(sizeof(Edge));
    tmp->connection = connected;
    tmp->G = weight;
    push_edge(&base->edges, tmp);

    Edge *tmp2 = (Edge*)malloc(sizeof(Edge));
    tmp2->connection = base;
    tmp2->G = weight;
    push_edge(&connected->edges, tmp2);

    return tmp;
}
