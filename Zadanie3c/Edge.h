#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

typedef struct Vertex Vertex;

struct Edge;
typedef struct Edge
{
    struct Edge *next;
    Vertex * connection;
    unsigned int G;
}Edge;

struct EdgeList;
typedef struct EdgeList
{
    int _count;
    Edge *_begin;
    Edge *_end;
}EdgeList;


Edge *push_edge( EdgeList *e_list, Edge* edge );

#endif // EDGE_H_INCLUDED
