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
    Vertex * ver_5 = graf_add_vertex(&graf, 'e');
    Vertex * ver_6 = graf_add_vertex(&graf, 'f');
    Vertex * ver_7 = graf_add_vertex(&graf, 'g');
    Vertex * ver_8 = graf_add_vertex(&graf, 'h');
    Vertex * ver_9 = graf_add_vertex(&graf, 'i');
    Vertex * ver_10 = graf_add_vertex(&graf, 'j');

    connect_vertex(ver_1, ver_2, 2);
    connect_vertex(ver_1, ver_3, 2);
    connect_vertex(ver_1, ver_4, 4);

    print_graf(&graf);
    return 0;
}
