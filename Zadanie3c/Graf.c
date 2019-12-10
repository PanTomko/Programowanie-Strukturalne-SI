#include "Graf.h"

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

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

Path *push_path( PathList *p_list, Path* path )
{
    path->next = NULL;

    if(p_list->_begin == NULL)
        p_list->_begin = path;
    else
        p_list->_end->next = path;

    path->prev = p_list->_end;
    p_list->_end = path;


    p_list->_count++;
    return path;
}

Path * erase_path( PathList *p_list, Path* path )
{
    for(Path * it = p_list->_begin; it != NULL; it = it->next)
    {
        if(path == it)
        {
            p_list->_count--;
            if(p_list->_count == 0)
            {
                p_list->_begin = NULL;
                p_list->_end = NULL;

                return path;
            }


            if(path->prev != NULL)
                path->prev->next = path->next;
            else
                p_list->_begin = path->next;

            if(path->next != NULL)
                path->next->prev = path->prev;
            else
                p_list->_end = path->prev;

            return path;
        }
    }
}

Path *find_path_fv(PathList *p_list, Vertex* vertex)
{
    for(Path * it = p_list->_begin; it != NULL; it = it->next)
    {
        if(it->from == vertex) return it;
    }

    return NULL;
}

PathList * graf_get_shotrtest_path(Graf *graf, Vertex *start_v, Vertex *end_v)
{
    Path * looked;
    Path * tmp_looked;

    PathList open;
    open._begin = NULL;
    open._end = NULL;
    open._count = 0;

    PathList close;
    close._begin = NULL;
    close._end = NULL;
    close._count = 0;

    PathList * shortest = (PathList*)malloc(sizeof(PathList));
    shortest->_begin = NULL;
    shortest->_end = NULL;
    shortest->_count = 0;

    // insert to open
    for(Vertex * it = graf->vertexs._begin; it != NULL; it = it->next)
    {
        Path * tmp = (Path*)malloc(sizeof(Path));
        tmp->from = it;

        if(it == start_v)
        {
            tmp->shortest = 0;
            tmp->to = tmp->from;
            looked = tmp;
        }
        else
        {
            tmp->shortest = INT_MAX;
        }


        push_path(&open, tmp);
    }

    // Djikstar
    int min;
    while(open._count != 0)
    {
        min = INT_MAX;
        tmp_looked = NULL;
        for(Edge * it = looked->from->edges._begin; it != NULL; it = it->next)
        {
            if(min > it->G)
            {
                if( find_path_fv(&open, it->connection) != NULL )
                {
                    min = it->G;
                    tmp_looked = find_path_fv(&open, it->connection);
                }
            }

            // Update shortest to X node
            Path * tmp_path = find_path_fv(&open, it->connection);
            if(tmp_path != NULL)
            {
                if(it->G + looked->shortest < tmp_path->shortest)
                {
                    tmp_path->shortest = it->G + looked->shortest;
                    tmp_path->to = looked->from;
                }
            }

        }

        push_path(&close,  erase_path(&open, looked));
        looked = tmp_looked;
        if(looked == NULL) looked = open._begin;
    }

    looked = find_path_fv(&close, end_v);
    Path * looked_end = find_path_fv(&close, start_v);
    while(looked != looked_end)
    {
        erase_path(&close, looked);
        push_path(shortest, looked);
        looked = find_path_fv(&close, looked->to);
    }
    erase_path(&close, looked);
    push_path(shortest, looked);

    clear_PathList(&close);
    return shortest;
}

PathList * graf_get_shotrtest_path_ws(Graf *graf, Vertex *start_v, Vertex *end_v)
{
    Path * looked;
    Path * tmp_looked;

    PathList open;
    open._begin = NULL;
    open._end = NULL;
    open._count = 0;

    PathList close;
    close._begin = NULL;
    close._end = NULL;
    close._count = 0;

    PathList * shortest = (PathList*)malloc(sizeof(PathList));
    shortest->_begin = NULL;
    shortest->_end = NULL;
    shortest->_count = 0;

    // insert to open
    for(Vertex * it = graf->vertexs._begin; it != NULL; it = it->next)
    {
        Path * tmp = (Path*)malloc(sizeof(Path));
        tmp->from = it;

        if(it == start_v)
        {
            tmp->shortest = 0;
            tmp->to = tmp->from;
            looked = tmp;
        }
        else
        {
            tmp->shortest = INT_MAX;
        }

        push_path(&open, tmp);
    }

    // Wszerz
    while(open._count != 0)
    {
        for(Edge * it = looked->from->edges._begin; it != NULL; it = it->next)
        {
            // Update shortest to X node
            Path * tmp_path = find_path_fv(&open, it->connection);
            if(tmp_path != NULL)
            {
                if(1 + looked->shortest < tmp_path->shortest)
                {
                    tmp_path->shortest = 1 + looked->shortest;
                    tmp_path->to = looked->from;
                }
            }
        }

        push_path(&close,  erase_path(&open, looked));
        looked = open._begin;
    }

    looked = find_path_fv(&close, end_v);
    Path * looked_end = find_path_fv(&close, start_v);
    while(looked != looked_end)
    {
        erase_path(&close, looked);
        push_path(shortest, looked);
        looked = find_path_fv(&close, looked->to);
    }
    erase_path(&close, looked);
    push_path(shortest, looked);

    clear_PathList(&close);
    return shortest;
}

void print_path( PathList *p_list )
{

    for(Path * it = p_list->_end; it != p_list->_begin; it = it->prev)
    {
        printf("%c --> ", it->from->symbol);
    }
    printf("%c", p_list->_begin->from->symbol);
}

void clear_PathList(PathList *p_list)
{
    Path *tmp;
    for(Path * it = p_list->_begin; it != NULL;)
    {
        tmp = it->next;
        free(it);
        it = tmp;
    }
    free(p_list);
}

void visit_vertex( Vertex * vertex )
{
    vertex->visted = 1;
    printf("%c --> ", vertex->symbol);
    for(Edge * it = vertex->edges._begin; it != NULL; it = it->next)
        if(it->connection->visted == 0) visit_vertex(it->connection);
    printf("(%c) --> ", vertex->symbol);
}

void DFS(Graf * graf)
{
    for(Vertex * it = graf->vertexs._begin; it != NULL; it = it->next)
        it->visted = 0;

    for(Vertex * it = graf->vertexs._begin; it != NULL; it = it->next)
        if(it->visted == 0)
            visit_vertex(it);
}
