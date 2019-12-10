#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED
#include "Vertex.h"

////////////// Store information for Djikstar'a Algorithm
typedef struct Path
{
    Vertex * from;
    Vertex * to;
    int shortest;

    struct Path * next;
    struct Path * prev;
}Path;

typedef struct PathList
{
    int _count;
    Path *_begin;
    Path *_end;
}PathList;

Path *push_path( PathList *p_list, Path* path );
Path *erase_path( PathList *p_list, Path* path );
Path *find_path_fv(PathList *p_list, Vertex* vertex);
void clear_PathList(PathList *p_list);
//int path_total_weight(PathList *v_list);
void print_path( PathList *p_list );
///////////////

typedef struct Graf
{
    VertexList vertexs;
}Graf;

void ini_graf( Graf *graf, Vertex *head );
void print_graf( Graf *graf );
Vertex *graf_add_vertex( Graf *graf, char symbol );
PathList * graf_get_shotrtest_path(Graf *graf, Vertex *start_v, Vertex *end_v);
PathList * graf_get_shotrtest_path_ws(Graf *graf, Vertex *start_v, Vertex *end_v);
void DFS(Graf * graf);

#endif // GRAF_H_INCLUDED
