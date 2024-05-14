#include <stdio.h>
#include <stdlib.h>

// Definisi struktur data
typedef struct t_kerajaan *address;
typedef struct t_kerajaan {
    char nama;
    int hp; // health point
    int p_pow, p_int, p_inf; // power, intelligence, influence
    address nb, fs, parent; // next brother, first son, parent
} kerajaan;
typedef address royal_tree;
typedef address king;



int max_point(address node1, address node2) {
    int max1 = node1->hp + node1->p_pow + node1->p_int + node1->p_inf;
    int max2 = node2->hp + node2->p_pow + node2->p_int + node2->p_inf;
    return (max1 > max2) ? max1 : max2;
}



 // Membandingkan poin dua node
    int max_value = max_point(node1, node2);
    printf("Maximum points between nodes: %d\n", max_value);



