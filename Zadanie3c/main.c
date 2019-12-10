#include <stdio.h>
#include <stdlib.h>

#include "Graf.h"

int main()
{
    Graf graf;
    ini_graf(&graf, NULL);

    Vertex * ver_1 = graf_add_vertex(&graf, 'a');
    Vertex * ver_2 = graf_add_vertex(&graf, 'b');
    Vertex * ver_3 = graf_add_vertex(&graf, 'c');
    Vertex * ver_4 = graf_add_vertex(&graf, 'd');
    //Vertex * ver_5 = graf_add_vertex(&graf, 'e');

    connect_vertex(ver_1, ver_2, 2);
    connect_vertex(ver_2, ver_3, 1);
    connect_vertex(ver_3, ver_4, 1);
    connect_vertex(ver_4, ver_1, 1);
    //connect_vertex(ver_4, ver_5, 1);

    print_graf(&graf);
    PathList *shortest_path = graf_get_shotrtest_path(&graf, ver_1, ver_3);
    PathList *shortest_path_ws = graf_get_shotrtest_path_ws(&graf, ver_1, ver_3);

    printf("\n");
    print_path(shortest_path);
    printf("\ntotal length : %d\n", shortest_path->_begin->shortest);

    printf("\n");
    print_path(shortest_path_ws);
    printf("\ntotal length : %d\n", shortest_path_ws->_begin->shortest);

    printf("\n");
    DFS(&graf);
    return 0;
}
