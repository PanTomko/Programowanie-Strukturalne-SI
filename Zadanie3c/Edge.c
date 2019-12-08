#include "Edge.h"
//#include "Vertex.h"

#include <stdlib.h>

Edge *push_edge(EdgeList *e_list, Edge* edge )
{
    edge->next = NULL;

    if(e_list->_begin == NULL)
        e_list->_begin = edge;
    else
        e_list->_end->next = edge;

    e_list->_end = edge;

    e_list->_count++;
    return edge;
}
