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

void fill_node(address node, int level) {
    if (node == NULL)
        return;

    switch (level) {
        case 0: // King
            node->hp = 100;
            node->p_pow = 100;
            node->p_int = 100;
            node->p_inf = 100;
            break;
        case 1: // Queen and King�s Mistresses
            node->hp = 100;
            node->p_pow = rand() % 61 + 20; // 20-80
            node->p_int = rand() % 71 + 30; // 30-100
            node->p_inf = rand() % 51 + 50; // 50-100
            break;
        case 2: // King�s Child
            node->hp = 100;
            node->p_pow = rand() % 41 + 30; // 30-70
            node->p_int = rand() % 41 + 30; // 30-70
            node->p_inf = rand() % 41 + 30; // 30-70
            break;
        case 3: // King�s Child Spouse
            node->hp = 100;
            node->p_pow = rand() % 21 + 20; // 20-40
            node->p_int = rand() % 21 + 20; // 20-40
            node->p_inf = rand() % 41 + 20; // 20-60
            break;
        case 4: // King�s Grandchild
            node->hp = 100;
            node->p_pow = rand() % 41; // 0-40
            node->p_int = rand() % 41; // 0-40
            node->p_inf = rand() % 41; // 0-40
            break;
        default:
            break;
    }
}
